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

#if !defined(__clang__)

#include <catch2/catch.hpp>

#include <iostream>
#include <utility>

// FIXME: clang++-9 doesn't work
// clang-format off
int counter = 0;
using PairII = std::pair<int, int>;
using PairID = std::pair<int, double>;
bool operator<(const PairII& t1, const PairII& t2) { counter++; return t1.first < t2.first; }
bool operator<(const PairID& t1, const PairID& t2) { counter++; return t1.first > t2.first; }
// clang-format on

TEST_CASE("[Pair]: CompareTest") {
  REQUIRE(PairII(1, 0) < PairII(2, 0));
  REQUIRE(counter == 1);
  REQUIRE(PairID(2, 0) < PairID(1, 0));
  REQUIRE(counter == 2);
}

#endif
