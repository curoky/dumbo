#pragma once
#include <sys/time.h>

#include <atomic>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using namespace std::string_literals;  // NOLINT

namespace trace {

inline int64_t nowInUsec() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (long)tv.tv_sec * 1000 * 1000 + tv.tv_usec;
}

struct TraceData {
  enum class Type { Record = 0, Bind = 1 };
  struct Record {
    std::string key;
    std::string event;
    int64_t stime;
  };
  struct Bind {
    std::string akey;
    std::string bkey;
  };

  std::string toString() const {
    if (type == Type::Record) {
      return std::string("{ record: [" + std::to_string(record.stime) + "," +
                         std::to_string(ptid_) + "," + record.key + "," + record.event + "]}");
    } else if (type == Type::Bind) {
      return std::string("{ bind: [" + std::to_string(ptid_) + "," + bind.akey + "," + bind.bkey +
                         "]}");
    } else {
      return "{ }";
    }
  }
  std::thread::id tid_;
  pthread_t ptid_;
  Type type;
  Record record;
  Bind bind;
};

class TraceAgent;

class TraceCollector : public std::enable_shared_from_this<TraceCollector> {
 public:
  static TraceCollector& ins() {
    thread_local static auto tc = makeTraceCollector();
    return *tc;
  }

  static std::shared_ptr<TraceCollector> makeTraceCollector();

  TraceCollector() : tid_(std::this_thread::get_id()), ptid_(pthread_self()) {}

  void appendData(const std::string& key, const std::string& event, int64_t stime) {
    datas_.push_back({tid_, ptid_, TraceData::Type::Record, {key, event, stime}, {}});
    w_size_.fetch_add(1);
  }

  void appendBind(const std::string& akey, const std::string& bkey) {
    datas_.push_back({tid_, ptid_, TraceData::Type::Bind, {}, {akey, bkey}});
    w_size_.fetch_add(1);
  }

  //  private:
  std::thread::id tid_;
  pthread_t ptid_;
  std::atomic_int r_size_{0};
  std::atomic_int w_size_{0};
  std::vector<TraceData> datas_;
};

class TraceAgent {
 public:
  static TraceAgent& ins() {
    static TraceAgent ta;
    return ta;
  }

  void registerCollector(std::shared_ptr<TraceCollector> tc) {
    printf("TraceAgent: registerCollector\n");
    std::lock_guard<std::mutex> _(tcs_mutex_);
    tcs_.push_back(std::move(tc));
  }

  ~TraceAgent() {
    printf("TraceAgent: destruct\n");
    stop();
  }

 private:
  TraceAgent() {
    // char * env = std::get_env("trace_");
    const char* env_dump_path = getenv("trace_dump_path");
    if (env_dump_path) {
      dump_path_ = std::string(getenv("trace_dump_path"));
    } else {
      dump_path_ = "trace.log";
    }
    const char* env_verbose = getenv("trace_verbose");
    if (env_verbose) {
      verbose_ = true;
    }

    printf("TraceAgent: dump to %s\n", dump_path_.c_str());
    running_.store(true);
    report_thread_ = std::thread(&TraceAgent::run, this);
  }

  void stop() {
    if (report_thread_.joinable()) {
      printf("TraceAgent: try stop report_thread\n");
      running_.store(false);
      report_cv_.notify_one();
      report_thread_.join();
      printf("TraceAgent: report_thread stoped\n");
    }
  }

  void appendToFile(const std::list<std::string>& datas) {
    std::ofstream dump_file;
    dump_file.open(dump_path_, std::ios::app);
    if (dump_file.is_open()) {
      for (const auto& data : datas) {
        dump_file << data << "\n";
      }
    } else {
      printf("TraceAgent: dump_path can't open \n");
    }
    dump_file.close();
  }

  void batchDump() {
    printf("TraceAgent: report_thread batchDump\n");
    std::list<std::string> datas;
    {
      std::lock_guard<std::mutex> _(tcs_mutex_);
      for (auto tc : tcs_) {
        int startIdx = tc->r_size_.load();
        int endIdx = tc->w_size_.load();
        if (endIdx - startIdx > 1) {
          for (int i = startIdx; i < endIdx; ++i) {
            std::string data = tc->datas_[i].toString();
            // printf("%s\n", data.c_str());
            datas.push_back(std::move(data));
          }
          tc->r_size_.store(endIdx);
        }
      }
    }
    appendToFile(datas);
  }

  void run() {
    printf("TraceAgent: report_thread stared\n");
    pthread_setname_np(pthread_self(), "trace_agent");
    std::this_thread::sleep_for(std::chrono::seconds(warmup_time_sec_));

    while (running_.load() == true) {
      std::unique_lock<std::mutex> lock(report_mutex_);
      std::cv_status status = report_cv_.wait_for(lock, std::chrono::seconds(1));
      lock.unlock();
      if (status == std::cv_status::timeout) {
        // LOG(INFO) << "don't receive stop notify, continue.";
        batchDump();
      } else {
        // LOG(INFO) << "receive stop notify, stop loop.";
        break;
      }
    }
    batchDump();
  }

  int warmup_time_sec_ = 1;
  std::string dump_path_;
  bool verbose_{false};

  std::thread report_thread_;
  std::mutex report_mutex_;
  std::condition_variable report_cv_;
  std::atomic<bool> running_;
  std::mutex tcs_mutex_;
  std::list<std::shared_ptr<TraceCollector>> tcs_;
};

inline std::shared_ptr<TraceCollector> TraceCollector::makeTraceCollector() {
  auto tc = std::make_shared<TraceCollector>();
  // FIXME: when datas_ overflow, not thread-safe.
  tc->datas_.reserve(200000);
  TraceAgent::ins().registerCollector(tc);
  return tc;
}

}  // namespace trace

// 给一个 key 打点
inline void tt_emit(const std::string& key, const std::string& event,
                    int64_t stime = trace::nowInUsec()) {
  trace::TraceCollector::ins().appendData(key, event, stime);
}

// 将两个 key 绑定
inline void tt_bind(const std::string& akey, const std::string& bkey) {
  trace::TraceCollector::ins().appendBind(akey, bkey);
}
