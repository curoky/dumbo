/**
 * Copyright 2020 curoky(cccuroky@gmail.com).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ----------------------------------------------------------------------------
 * @file: solution.cc
 * ----------------------------------------------------------------------------
 */

#include <glog/logging.h>  // for COMPACT_GOOGLE_LOG_INFO, LOG, LogMessage

#include <atomic>              // for atomic
#include <chrono>              // for seconds
#include <condition_variable>  // for condition_variable, cv_status, cv_status::timeout
#include <mutex>               // for mutex, unique_lock
#include <ostream>             // for operator<<
#include <thread>              // for thread

class BackgroudTask {
 public:
  BackgroudTask() {
    running_.store(true);
    th_ = std::thread(&BackgroudTask::run, this);
  }

  void stop() {
    if (th_.joinable()) {
      running_.store(false);
      cv_.notify_one();
      th_.join();
    }
  }

  void run() {
    while (running_.load() == true) {
      std::unique_lock<std::mutex> lock(mutex_);
      std::cv_status status = cv_.wait_for(lock, std::chrono::seconds(10));
      lock.unlock();
      if (status == std::cv_status::timeout) {
        LOG(INFO) << "don't receive stop notify, continue.";

        // do some operating.
      } else {
        LOG(INFO) << "receive stop notify, stop loop.";
        break;
      }
    }
  }

 private:
  std::thread th_;
  std::mutex mutex_;
  std::condition_variable cv_;
  std::atomic<bool> running_;
};

int main(int argc, char const *argv[]) {
  BackgroudTask mth;
  mth.stop();
  return 0;
}
