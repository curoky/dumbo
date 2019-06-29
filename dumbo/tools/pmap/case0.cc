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
 */


// Ref: https://my.oschina.net/tz8101/blog/629739
// Run: pmap -X $(pidof case0) > pmap.log

#include <pthread.h>  // for pthread_t, pthread_attr_init, pthread_attr_setstacksize, pthread_attr_t, pthread_create, pthread_join
#include <sys/types.h>  // for int8_t

#include <cassert>  // for assert
#include <chrono>   // for seconds
#include <thread>   // for sleep_for
#include <vector>   // for vector, size_t

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
