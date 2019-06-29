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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <regex>  // for match_results<>::_Base_type, regex_match, regex_search, smatch, sub_match, regex_token_iterator, sub_match<>::string_type
#include <string>  // for operator==, basic_string, string
#include <vector>  // for vector, allocator

TEST_CASE("[Regex]: MatchTest") {
  std::string target = "abcdabcd";
  const std::regex pattern("abc[a-z]",
                           std::regex_constants::ECMAScript | std::regex_constants::icase);
  std::smatch match_result;

  // 尽可能的完整匹配
  REQUIRE(std::regex_match(target, match_result, pattern) == false);
  REQUIRE(match_result.size() == 0);

  // 第一个匹配
  REQUIRE(std::regex_search(target, match_result, pattern) == true);
  REQUIRE(match_result.size() == 1);
  REQUIRE(match_result[0].str() == "abcd");

  // 全部的匹配
  // default constructor = end-of-sequence:
  std::sregex_token_iterator rend;
  for (auto iter = std::sregex_token_iterator(target.begin(), target.end(), pattern); iter != rend;
       ++iter) {
    REQUIRE(iter->str() == "abcd");
  }
}
