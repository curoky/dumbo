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
 * @file: judge_main_thread.cc
 * ----------------------------------------------------------------------------
 */

// reference: http://www.cplusplus.com/reference/thread/thread/get_id/

#include <syscall.h>  // for SYS_gettid
#include <unistd.h>   // for getpid, syscall

#include <iostream>  // for operator<<, endl, basic_ostream, cout, ostream
#include <thread>    // for get_id, thread, operator==, thread::id

std::thread::id main_thread_id = std::this_thread::get_id();

void judge_with_thread() {
  if (main_thread_id == std::this_thread::get_id()) {
    std::cout << "This is in main thread." << std::endl;
  } else {
    std::cout << "This is not in main thread." << std::endl;
  }
}

void judge_with_syscall() {
  if (getpid() != syscall(SYS_gettid)) {
    // fprintf(stderr, "%s should be called in main() before creating any thread\n", __func__);
    // abort();
    std::cout << "This is not in main prograss." << std::endl;
  } else {
    std::cout << "This is in main prograss." << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  {
    judge_with_thread();
    std::thread th(judge_with_thread);
    th.join();
  }
  {
    judge_with_syscall();
    std::thread th(judge_with_syscall);
    th.join();
  }
  return 0;
}
