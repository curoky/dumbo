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
 */

#if __has_include(<source_location>)
#include <source_location>
#else
#include <experimental/source_location>

namespace std {
using namespace experimental;  // NOLINT
}
#endif

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, CHECK, EndsWith, REQUIRE, REQUIRE_THAT, TEST_CASE

#include <string>  // for string, basic_string, operator==, allocator, to_string
#include <string_view>  // for string_view
#include <vector>  // for vector

std::vector<std::string> log(std::string_view message, const std::source_location& location =
                                                           std::source_location::current()) {
  std::vector<std::string> res;
  res.push_back(location.file_name());
  res.push_back(std::to_string(location.line()));
  res.push_back(std::to_string(location.column()));
  res.push_back(location.function_name());
  return res;
}

TEST_CASE("[SourceLocation]: basic usage") {
  auto ret = log("hahaha");
  REQUIRE(ret.size() == 4);
  REQUIRE_THAT(ret[0], Catch::Matchers::EndsWith("source_location.cc"));
  REQUIRE(ret[1] == "45");
  REQUIRE(ret[2] == "0");
  REQUIRE(ret[3] == "____C_A_T_C_H____T_E_S_T____0");
}
