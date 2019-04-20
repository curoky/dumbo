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
 * @file: likely.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"

namespace {
int iabs(int x) {
  // FIXME: why attributes at the beginning of statement are ignored [-Wattributes]GCC
  if (x < 0) [[unlikely]] {
    return -x;
  } else {
    return x;
  }
}
#pragma GCC diagnostic pop

int iabs2(int x) {
  switch (x) {
    case 1:
      return 1;
      [[likely]] case -1 : return 1;
  }
  return 0;
}
}  // namespace

TEST_CASE("[Likely]: simple test") {
  REQUIRE(iabs(-1) == 1);
  REQUIRE(iabs(1) == 1);
  REQUIRE(iabs2(-1) == 1);
  REQUIRE(iabs2(1) == 1);
}
