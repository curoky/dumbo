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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <folly/TokenBucket.h>  // for TokenBucket
#include <stddef.h>             // for size_t

TEST_CASE("[TokenBucket]: basic usage") {
  {
    folly::TokenBucket tokenBucket(1000, 1, 0);
    size_t count = 0;

    double time = 0.001;
    while (time < 1.000) {
      while (tokenBucket.consume(1, time)) {
        count++;
      }
      time += 0.001;
    }
    // REQUIRE(count == 1000);
    REQUIRE(990 <= count);
    REQUIRE(count <= 1000);
  }
  {
    // folly::TokenBucket tokenBucket(10, 10, 0);
    // size_t count = 0;
    // while (tokenBucket.consume(1, 0.1)) { count += 1; }
    // REQUIRE(count == 10);
  }
}
