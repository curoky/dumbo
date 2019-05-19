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
 * @file: find.cc
 * ----------------------------------------------------------------------------
 */

/**
 * @brief Heap operations
 *    - find          finds the first element satisfying specific criteria
 *    - find_if
 *    - find_if_not
 *    - find_end      finds the last sequence of elements in a certain range
 *    - find_first_of searches for any one of a set of elements
 *    - adjacent_find finds the first two adjacent items that are equal (or satisfy a given
 * predicate)
 *    - search        searches for a range of elements
 *    - search_n      searches a range for a number of consecutive copies of an element
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <algorithm>  // for find, find_end, find_first_of, adjacent_find, find_if, find_if_not
#include <iterator>   // for distance
#include <vector>     // for vector

TEST_CASE("[Find]: FindTest") {
  std::vector<int> nub = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5};

  REQUIRE(std::ranges::find(nub, 3) - nub.begin() == 3);
  REQUIRE(std::ranges::find(nub, 6) == nub.end());

  // {
  //   auto iter3 = std::ranges::find_if(nub, [](int a) { return a == 3; });
  //   auto iter4 = std::ranges::find_if_not(nub, [](int a) { return a == 1; });
  //   REQUIRE(*iter3 == 3);
  //   REQUIRE(*iter4 == 0);
  // }

  // std::vector<int> sub1 = {0, 1, 2};
  // std::vector<int> sub2 = {2, 3, 4};
  // auto ret5 = std::find_end(nub.begin(), nub.end(), sub1.begin(), sub1.end());
  // auto ret6 = std::find_end(nub.begin(), nub.end(), sub2.begin(), sub2.end());
  // REQUIRE(std::distance(nub.begin(), ret5) == 6);
  // REQUIRE(std::distance(nub.begin(), ret6) == 8);

  // auto ret7 = std::find_first_of(nub.begin(), nub.end(), sub1.begin(), sub1.end());
  // auto ret8 = std::find_first_of(nub.begin(), nub.end(), sub2.begin(), sub2.end());
  // REQUIRE(std::distance(nub.begin(), ret7) == 0);
  // REQUIRE(std::distance(nub.begin(), ret8) == 2);
}

// TEST_CASE("[Find]: AdjacentFindTest") {
//   std::vector<int> nub = {0, 1, 1, 2, 2};
//   auto ret = std::adjacent_find(nub.begin(), nub.end());
//   REQUIRE(std::distance(nub.begin(), ret) == 1);
// }

// TEST_CASE("[Find]: search") {
//   std::string target = "abcdefg";
//   std::string partten = "abc";
//   REQUIRE(std::ranges::search(target, partten) != target.end());
// }
