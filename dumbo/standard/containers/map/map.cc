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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_...

#include <map>     // for allocator, map
#include <memory>  // for shared_ptr, operator==
#include <string>  // for string

TEST_CASE("[Map]: KeyNotExitsTest") {
  std::map<std::string, std::shared_ptr<int>> mp;
  std::shared_ptr<int> ptr = mp["not exist"];
  REQUIRE(ptr == nullptr);

  std::map<int, int> mii;
  mii[1] += 1;
  REQUIRE(mii[1] == 1);
}
