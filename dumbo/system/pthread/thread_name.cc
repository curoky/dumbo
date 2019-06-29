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
 * @file: thread_name.cc
 * ----------------------------------------------------------------------------
 */

// Ref: <https://linux.die.net/man/3/pthread_getname_np>

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <pthread.h>         // for pthread_self, pthread_getname_np, pthread_setname_np
#include <stdio.h>           // for snprintf
#include <string>            // for allocator, basic_string, string, operator==

TEST_CASE("[ThreadName]: basic usage") {
  char buffer[16];
  snprintf(buffer, sizeof(buffer), "foo thread name");
  int rc = pthread_setname_np(pthread_self(), buffer);
  REQUIRE(rc == 0);

  char result[16];
  rc = pthread_getname_np(pthread_self(), result, 16);
  REQUIRE(rc == 0);
  REQUIRE(std::string(buffer) == std::string(result));
}
