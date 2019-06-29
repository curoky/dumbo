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
 * @file: cppitertools.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>      // for SourceLineInfo, StringRef, TEST_CASE
#include <cppitertools/zip.hpp>  // for Zipped, Zipped<>::Iterator, zip
#include <iostream>              // for operator<<, basic_ostream, basic_ostream::operator<<, char_traits, cout, ostream, basic_ostream<>::__ostream_type
#include <string>                // for string, basic_string, allocator, operator<<
#include <vector>                // for vector

TEST_CASE("[Cppitertools]: zip") {
  std::vector<int> ivec{1, 4, 9, 16, 25, 36};
  std::vector<std::string> svec{"hello", "good day", "goodbye"};

  // zip terminates on the shortest sequence, and is variadic
  std::cout << "zipping a vector of ints and a vector of strings\n";
  for (auto&& [i, s] : iter::zip(ivec, svec)) {
    std::cout << '(' << i << ", " << s << ")\n";
  }
}
