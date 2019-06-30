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
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE
#include <syscall.h>         // for SYS_gettid
#include <unistd.h>          // for syscall, pid_t

#include <iostream>  // for basic_ostream::operator<<, endl, basic_ostream<>::__ostream_type, cout, ostream

TEST_CASE("[Gettid]: ") {
  {
    pid_t tid = syscall(SYS_gettid);
    std::cout << tid << std::endl;
  }
  {
    // Library support was added in glibc 2.30.
    // Earlier glibc versions did not provide a wrapper for this system call,
    // necessitating the use of syscall(2).
    // pid_t tid = gettid();
    // std::cout << tid << std::endl;
  }
}
