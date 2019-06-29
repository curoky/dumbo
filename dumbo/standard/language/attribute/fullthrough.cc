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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_...

namespace {

int something() {
  static int count = 0;
  return count++;
}

void fallthrough(int i) {
  switch (i) {
    case 1:
      something();
      [[fallthrough]];
    case 2:
      something();
      [[fallthrough]];
    case 3:
      something();
      [[fallthrough]];
    default:
      something();
      break;
  }
}
}  // namespace

TEST_CASE("[Fullthrough]: base test") {
  fallthrough(2);
  REQUIRE(something() == 3);
}
