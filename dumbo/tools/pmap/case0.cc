
// Ref: https://my.oschina.net/tz8101/blog/629739
// Run: pmap -X $(pidof case0) > pmap.log

#include <gflags/gflags.h>
#include <pthread.h>

#include <cassert>
#include <chrono>
#include <thread>

static const size_t KB = 1024;
static const size_t MB = 1024 * KB;
static const size_t GB = 1024 * MB;

pthread_attr_t get_thread_attr(int size) {
  pthread_attr_t thread_attr;
  assert(pthread_attr_init(&thread_attr) == 0);

  int code = pthread_attr_setstacksize(&thread_attr, size);
  assert(code == 0);
  return thread_attr;
}

pthread_t run_thread_with(size_t stack_size, void* (*use_stack_size)(void*)) {
  pthread_attr_t pthread_attr = get_thread_attr(stack_size);
  pthread_t pthread;
  assert(pthread_create(&pthread, &pthread_attr, use_stack_size, nullptr) == 0);
  return pthread;
}

void* use_0K(void*) {
  [[maybe_unused]] int8_t buffer[1];
  std::this_thread::sleep_for(std::chrono::seconds(10000));
  return nullptr;
}

void* use_50K(void*) {
  [[maybe_unused]] int8_t buffer[50 * KB];
  std::this_thread::sleep_for(std::chrono::seconds(10000));
  return nullptr;
}

void* use_1MB(void*) {
  [[maybe_unused]] int8_t buffer[1 * MB];
  std::this_thread::sleep_for(std::chrono::seconds(10000));
  return nullptr;
}

void* use_10MB(void*) {
  [[maybe_unused]] int8_t buffer[10 * MB];
  std::this_thread::sleep_for(std::chrono::seconds(10000));
  return nullptr;
}

int main(int argc, char const* argv[]) {
  // clang-format off
  std::vector<pthread_t> threads = {
      run_thread_with(1 * MB, use_0K),
      run_thread_with(1 * MB, use_50K),
      // run_thread_with(1 * MB, use_1MB),
      run_thread_with(10 * MB, use_1MB),
      // run_thread_with(10 * MB, use_10MB),
  };
  // clang-format on

  for (pthread_t t : threads) {
    pthread_join(t, nullptr);
  }
  return 0;
}
