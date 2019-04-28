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
 * @file: folly-fmt.cc
 * ----------------------------------------------------------------------------
 */

// https://github.com/facebook/folly/blob/master/folly/docs/Format.md

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <folly/Format.h>  // for sformat, svformat

#include <map>     // for map
#include <string>  // for string, operator==, basic_string, operator<
#include <tuple>   // for tuple
#include <vector>  // for vector

TEST_CASE("[Folly-fmt]: format test") {
  REQUIRE(folly::sformat("{}-{}-{}", "1", "2", "3") == "1-2-3");
  REQUIRE(folly::sformat("{}-{}-{}", "1", "2", "3") == "1-2-3");
  REQUIRE(folly::sformat("{0}-{1}-{2}", "1", "2", "3") == "1-2-3");
  REQUIRE(folly::sformat("{0}-{0}-{0}", "1", "2", "3") == "1-1-1");
  REQUIRE(folly::sformat("{2}-{1}-{0}", "1", "2", "3") == "3-2-1");
}

TEST_CASE("[Folly-fmt]: container arg test") {
  std::vector<int> v{1, 2, 3};
  std::map<std::string, std::string> m{{"key", "value"}};
  REQUIRE(folly::sformat("{1[key]} - {0[1]}", v, m) == "value - 2");

  // map
  REQUIRE(folly::svformat("{key}", m) == "value");

  // tuple
  std::tuple<int, std::string, int> t{42, "hello", 23};
  REQUIRE(folly::svformat("{0} {2} {1}", t) == "42 23 hello");
}
