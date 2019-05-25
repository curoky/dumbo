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
 * @file: array.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE

#include <algorithm>  // for sort, reverse_copy
#include <array>      // for array
#include <iostream>   // for operator<<, basic_ostream::operator<<, cout, basic_ostream, ostream
#include <iterator>   // for ostream_iterator
#include <string>     // for allocator, operator<<, string

TEST_CASE("[Array]: base test") {
  // construction uses aggregate initialization

  // double-braces required in C++11 prior to the CWG 1270 revision
  // (not needed in C++11 after the revision and in C++14 and beyond)
  std::array<int, 3> a1{{1, 2, 3}};
  std::array<int, 3> a11{1, 2, 3};

  std::array<int, 3> a2 = {1, 2, 3};  // never required after =
  std::array<std::string, 2> a3 = {std::string("a"), "b"};

  // container operations are supported
  std::sort(a1.begin(), a1.end());
  std::sort(a11.begin(), a11.end());

  std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

  std::cout << '\n';

  // ranged for loop is supported
  for (const auto& s : a3) std::cout << s << ' ';
}

TEST_CASE("[Array]: base test2") {
  std::array<int, 2> arr;
  arr[0] = 1;
  arr[1] = 2;
  REQUIRE(arr[0] == 1);
  REQUIRE(arr[1] == 2);
}
