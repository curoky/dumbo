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

#include "absl/numeric/int128.h"

#include <catch2/catch.hpp>

TEST_CASE("[Int128]: simple test") {
  absl::int128 one = 1;
  absl::int128 two = one + 1;
  absl::int128 four = two * two;
  REQUIRE(two == absl::MakeInt128(0, 2));
  REQUIRE(two == absl::int128{2});
  REQUIRE(four == absl::int128(4));
}
