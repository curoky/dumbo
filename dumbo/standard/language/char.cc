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

#include <catch2/catch.hpp>

#include <string>

TEST_CASE("[Char]: basic test") {
  char a = '\0';
  char b = static_cast<char>(0);
  char c = 0;
  REQUIRE(!a);
  REQUIRE(!b);
  REQUIRE(!c);
  REQUIRE(a == b);
  REQUIRE(a == c);
  REQUIRE('\0' == 0);

  std::string as = "xxxx";
  as[0] = '\0';
  std::string bs = "xxxx";
  bs[0] = 0;
  REQUIRE(as.size() == 4);
  REQUIRE(bs.size() == 4);
  REQUIRE(as == bs);
}
