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
 * @file: sort.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <algorithm>  // for is_sorted_until, is_sorted, nth_element, partial_sort, sort
#include <array>      // for array
#include <iterator>   // for distance, begin, end
#include <vector>     // for vector

TEST_CASE("[Sort]: SortTest") {
  int digits[] = {3, 1, 4, 1, 5};
  REQUIRE_FALSE(std::is_sorted(std::begin(digits), std::end(digits)));
  std::sort(std::begin(digits), std::end(digits));
  REQUIRE(std::is_sorted(std::begin(digits), std::end(digits)));
}

TEST_CASE("[Sort]: IsSortedUntilTest") {
  std::vector<int> nub1 = {1, 2, 3, 4, 5};
  std::vector<int> nub2 = {2, 3, 4, 5, 1};
  std::vector<int> nub3 = {3, 4, 5, 1, 2};
  REQUIRE(std::distance(nub1.begin(), std::is_sorted_until(nub1.begin(), nub1.end())) == 5);
  REQUIRE(std::distance(nub2.begin(), std::is_sorted_until(nub2.begin(), nub2.end())) == 4);
  REQUIRE(std::distance(nub3.begin(), std::is_sorted_until(nub3.begin(), nub3.end())) == 3);
}
TEST_CASE("[Sort]: PartialSortTest") {
  std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
  std::partial_sort(s.begin(), s.begin() + 3, s.end());
  REQUIRE(s[0] == 0);
  REQUIRE(s[1] == 1);
  REQUIRE(s[2] == 2);
}

TEST_CASE("[Sort]: NthElementTest") {
  std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
  std::nth_element(s.begin(), s.begin() + 0, s.end());
  REQUIRE(s[0] == 0);
  std::nth_element(s.begin(), s.begin() + 1, s.end());
  REQUIRE(s[1] == 1);
  std::nth_element(s.begin(), s.begin() + 2, s.end());
  REQUIRE(s[2] == 2);
  std::nth_element(s.begin(), s.begin() + 3, s.end());
  REQUIRE(s[3] == 3);
}
