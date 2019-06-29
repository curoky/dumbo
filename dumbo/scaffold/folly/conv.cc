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
#include <folly/Conv.h>  // for to
#include <stdint.h>      // for int16_t, uint16_t

TEST_CASE("[Conv]: simple test") {
  int16_t x = 2;
  uint16_t y = 4;
  REQUIRE(folly::to<int>(x) == 2);  // zero overhead conversion
  REQUIRE(folly::to<int>(y) == 4);  // zero overhead conversion
}
