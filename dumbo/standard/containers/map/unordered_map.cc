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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <algorithm>      // for max
#include <unordered_map>  // for unordered_map, pair

TEST_CASE("[UnorderedMap]: insert when exists") {
  std::unordered_map<int, int> mp = {{1, 1}};
  REQUIRE(mp.emplace(1, 2).second == false);
  REQUIRE(mp.emplace(2, 2).second == true);
}
