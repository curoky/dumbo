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

/**
 * @brief Binary search operations (on sorted ranges)
 *        - lower_bound
 *        - ranges::lower_bound
 *        - upper_bound
 *        - ranges::upper_bound
 *        - binary_search
 *        - ranges::binary_search
 *        - equal_range
 *        - ranges::equal_range
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <algorithm>  // for lower_bound, upper_bound
#include <iterator>   // for distance
#include <vector>     // for vector

TEST_CASE("[Binary-search]: bound") {
  std::vector<int> nub = {0, 1, 2, 2, 3, 4};
  auto lower_2 = std::ranges::lower_bound(nub, 2);
  auto upper_2 = std::ranges::upper_bound(nub, 2);
  auto equal_2 = std::ranges::equal_range(nub, 2);

  REQUIRE(std::distance(nub.begin(), lower_2) == 2);
  REQUIRE(std::distance(nub.begin(), upper_2) == 4);
  REQUIRE(equal_2.begin() == lower_2);
  REQUIRE(equal_2.end() == upper_2);

  auto lower_4 = std::ranges::lower_bound(nub, 4);
  auto upper_4 = std::ranges::upper_bound(nub, 4);
  auto equal_4 = std::equal_range(nub.begin(), nub.end(), 4);

  REQUIRE(std::distance(nub.begin(), lower_4) == 5);
  REQUIRE(std::distance(nub.begin(), upper_4) == 6);
  REQUIRE(equal_4.first == lower_4);
  REQUIRE(equal_4.second == upper_4);
}

TEST_CASE("[Binary-search]: binary_search") {
  std::vector<int> nub = {0, 1, 2, 2, 3, 4};
  REQUIRE(std::ranges::binary_search(nub, 1) == true);
  REQUIRE(std::ranges::binary_search(nub, 5) == false);
}
