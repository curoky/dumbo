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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <stddef.h>  // for size_t

#include <algorithm>  // for transform
#include <iterator>   // for back_insert_iterator, back_inserter
#include <string>     // for string, basic_string, to_string, operator==
#include <vector>     // for vector

TEST_CASE("[Transform]: base test") {
  std::vector<int> ids = {0, 1, 2, 3, 4, 5};
  std::vector<std::string> ids_strs;

  std::transform(ids.begin(), ids.end(), std::back_inserter(ids_strs),
                 [](int c) { return std::to_string(c); });

  for (size_t i = 0; i < ids_strs.size(); ++i) {
    REQUIRE(ids_strs[i] == std::to_string(i));
  }
}
