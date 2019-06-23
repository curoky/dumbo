// REF: https://www.cnblogs.com/clover-toeic/p/4126594.html
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#include <iostream>
#include <thread>

#define INFO std::cout << "[" << pthread_self() << "]: " << __func__ << ": "

// void __register_signal__() __attribute__((constructor(101)));
void __register_signal__();

class Destructor {
 public:
  Destructor(size_t sleep_time) : sleep_time(sleep_time) {
    std::cout << "[Destructor]: construct!" << std::endl;
  }

  ~Destructor() {
    std::this_thread::sleep_for(std::chrono::seconds(sleep_time));
    message = "";
    std::cout << "[Destructor]: ~destruct!" << sleep_time << std::endl;
  }

  size_t sleep_time = 0;
  std::string message = "hhhhhhhhh";
};

static auto destructor_slow = std::make_shared<Destructor>(5);
static auto destructor_fast = std::make_shared<Destructor>(2);

int main() {
  __register_signal__();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  return 0;
}

void __signal_thread_handler__(sigset_t& sigset) {
  auto d = destructor_fast;
  INFO << "wait for signal..." << std::endl;
  int sig = 0;
  while (0 != sigwait(&sigset, &sig)) {
  }

  size_t check_round = 0;
  while (true) {
    INFO << "sleep_for 1s, message " << destructor_fast->message << ", check_round " << check_round++
         << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  INFO << "exit..." << std::endl;
}

static pthread_t sig_thread_id;
void __signal_handler__(int sig_num) {
  INFO << "before pthread_kill signal:" << sig_num << std::endl;
  int result = pthread_kill(sig_thread_id, sig_num);
  INFO << "after pthread_kill signal:" << sig_num << ", result:" << result << std::endl;
}

void __register_signal__() {
  // ignore SIGPIPE
  signal(SIGPIPE, SIG_IGN);

  // ignore follow sig for this thread.
  static sigset_t sigset;
  sigemptyset(&sigset);
  sigaddset(&sigset, SIGINT);
  sigaddset(&sigset, SIGTERM);
  pthread_sigmask(SIG_SETMASK, &sigset, NULL);

  std::thread sig_thread(__signal_thread_handler__, std::ref(sigset));
  sig_thread_id = sig_thread.native_handle();
  signal(SIGINT, __signal_handler__);
  signal(SIGTERM, __signal_handler__);
  sig_thread.detach();

  INFO << "finished" << std::endl;
}
