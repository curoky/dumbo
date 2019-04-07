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
 * @file: set.cc
 * ----------------------------------------------------------------------------
 */

/**
 * @brief example for set operations (on sorted ranges)
 *        - includes
 *        - ranges::includes
 *        - set_difference
 *        - ranges::set_difference
 *        - set_intersection
 *        - ranges::set_intersection
 *        - set_symmetric_difference
 *        - ranges::set_symmetric_difference
 *        - set_union
 *        - ranges::set_union
 */

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE

#include <algorithm>
#include <algorithm>  // for set_difference
#include <iterator>   // for insert_iterator, inserter
#include <set>
#include <vector>  // for vector, operator==

#include "dumbo/utilities/conv.h"

TEST_CASE("[Set]: set_difference") {
  // A - B
  std::vector<int> v1{1, 2, 5, 5, 5, 9};
  std::vector<int> v2{2, 5, 7};
  std::vector<int> v_diff;

  std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
                      std::inserter(v_diff, v_diff.begin()));
  REQUIRE(v_diff == toVec({1, 5, 5, 9}));

  v_diff.clear();
  std::ranges::set_difference(v1, v2, std::inserter(v_diff, v_diff.begin()));
  REQUIRE(v_diff == toVec({1, 5, 5, 9}));
}

TEST_CASE("[Set]: set_intersection") {
  // A ∩ B
  std::vector<int> v1{1, 2, 3, 4, 5, 6};
  std::vector<int> v2{1, 2, 3};
  std::vector<int> v3{1, 1, 1};

  std::vector<int> v_intersection;

  std::ranges::set_intersection(v1, v2, std::back_inserter(v_intersection));
  REQUIRE(v_intersection == toVec({1, 2, 3}));

  v_intersection.clear();
  std::ranges::set_intersection(v1, v3, std::back_inserter(v_intersection));
  REQUIRE(v_intersection == toVec({1}));
}

TEST_CASE("[Set]: set_symmetric_difference") {
  // (A ∪ B) - (A ∩ B)
  // clang-format off
  std::vector<int> v1{1,2,3,4,5,6,7,8     };
  std::vector<int> v2{        5,  7,  9,10};
  // clang-format on

  std::vector<int> v_symDifference;
  std::ranges::set_symmetric_difference(v1, v2, std::back_inserter(v_symDifference));
  REQUIRE(v_symDifference == toVec({1, 2, 3, 4, 6, 8, 9, 10}));
}

TEST_CASE("[Set]: set_union") {
  // clang-format off
  std::vector<int> v1 = {1, 2, 3, 4, 5, 5, 5};
  std::vector<int> v2 = {      3, 4, 5, 6, 7};
  // clang-format on
  std::vector<int> v_union;

  std::ranges::set_union(v1, v2, std::back_inserter(v_union));
  REQUIRE(v_union == toVec({1, 2, 3, 4, 5, 5, 5, 6, 7}));
}

TEST_CASE("[Set]: includes") {
  // A ⊇ B
  std::vector<char> v1 = {'a', 'b', 'c', 'f', 'h', 'x'};
  std::vector<char> v2 = {'a', 'b', 'c'};
  std::vector<char> v3 = {'a', 'c'};
  std::vector<char> v4 = {'a', 'a', 'b'};
  std::vector<char> v5 = {'g'};
  std::vector<char> v6 = {'a', 'c', 'g'};
  std::vector<char> v7 = {'A', 'B', 'C'};
  namespace ranges = std::ranges;

  auto no_case = [](char a, char b) { return std::tolower(a) < std::tolower(b); };

  REQUIRE(std::includes(v1.begin(), v1.end(), v2.begin(), v2.end()) == true);
  REQUIRE(std::ranges::includes(v1, v3) == true);
  REQUIRE(std::ranges::includes(v1, v4) == false);
  REQUIRE(std::ranges::includes(v1, v5) == false);
  REQUIRE(std::ranges::includes(v1, v6) == false);
  REQUIRE(std::ranges::includes(v1, v7) == false);
  REQUIRE(std::ranges::includes(v1, v7, no_case) == true);
}
