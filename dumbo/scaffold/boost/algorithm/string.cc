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

#include <boost/algorithm/string/case_conv.hpp>       // for to_lower_copy, to_upper_copy
#include <boost/algorithm/string/classification.hpp>  // for is_any_of
#include <boost/algorithm/string/constants.hpp>       // for token_compress_on
#include <boost/algorithm/string/erase.hpp>  // for erase_all_copy, erase_first_copy, erase_last_copy, erase_nth_copy
#include <boost/algorithm/string/join.hpp>       // for join
#include <boost/algorithm/string/predicate.hpp>  // for contains, ends_with, iequals, starts_with
#include <boost/algorithm/string/replace.hpp>    // for replace_all_copy
#include <boost/algorithm/string/split.hpp>      // for split
#include <boost/algorithm/string/trim.hpp>  // for trim_copy, trim_copy_if, trim_left_copy, trim_left_copy_if, trim_right_copy, trim_right_copy_if
#include <boost/iterator/iterator_traits.hpp>  // for iterator_value<>::type
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <algorithm>    // for equal
#include <string>       // for string, basic_string, operator==, operator""s, allocator
#include <string_view>  // for literals
#include <vector>       // for vector, operator==

using namespace std::literals;

TEST_CASE("[String]: JoinSplitTest") {
  std::vector<std::string> nubs = {"1", "2", "3", "4"};
  REQUIRE(boost::join(nubs, ",") == "1,2,3,4");

  boost::split(nubs, "1,2,3,4", boost::is_any_of(","));
  REQUIRE(nubs == std::vector<std::string>({"1", "2", "3", "4"}));

  boost::split(nubs, ",", boost::is_any_of(","));
  REQUIRE(nubs == std::vector<std::string>({"", ""}));

  boost::split(nubs, ",,", boost::is_any_of(","));
  REQUIRE(nubs == std::vector<std::string>({"", "", ""}));

  boost::split(nubs, ",,", boost::is_any_of(","), boost::token_compress_on);
  REQUIRE(nubs == std::vector<std::string>({"", ""}));

  boost::split(nubs, ",,,", boost::is_any_of(","), boost::token_compress_on);
  REQUIRE(nubs == std::vector<std::string>({"", ""}));
}

TEST_CASE("[String]: split") {
  std::string source =
      "tcp6       0      0 :::10010                :::*                    LISTEN      "
      "3735057/server";
  std::vector<std::string> nubs;
  boost::split(nubs, source, boost::is_any_of(" "), boost::token_compress_on);
  REQUIRE(nubs.size() == 7);
  REQUIRE(nubs[3] == ":::10010");
}

TEST_CASE("[String]: ReplaceTest") {
  REQUIRE(boost::replace_all_copy("123aaa123"s, "aaa", "123") == "123123123");
}

TEST_CASE("[String]: TrimTest") {
  REQUIRE(boost::trim_copy(" aaa "s) == "aaa");
  REQUIRE(boost::trim_left_copy(" aaa "s) == "aaa ");
  REQUIRE(boost::trim_right_copy(" aaa "s) == " aaa");

  REQUIRE(boost::trim_copy_if("* aaa *"s, boost::is_any_of("*")) == " aaa ");
  REQUIRE(boost::trim_left_copy_if("* aaa *"s, boost::is_any_of("*")) == " aaa *");
  REQUIRE(boost::trim_right_copy_if("* aaa *"s, boost::is_any_of("*")) == "* aaa ");
}

TEST_CASE("[String]: StartWithTest") {
  REQUIRE(boost::starts_with("abcde", "abc"));
  REQUIRE(boost::ends_with("abcde", "cde"));
  REQUIRE(boost::contains("abcde", "bcd"));
  REQUIRE(boost::iequals("abc", "ABc"));
}

TEST_CASE("[String]: EraseTest") {
  REQUIRE(boost::erase_all_copy("abcabcabc"s, "abc") == "");
  REQUIRE(boost::erase_first_copy("abc1abc2abc"s, "abc") == "1abc2abc");
  REQUIRE(boost::erase_last_copy("abc1abc2abc"s, "abc") == "abc1abc2");
  REQUIRE(boost::erase_nth_copy("abc1abc2abc"s, "abc", 1) == "abc12abc");
}

TEST_CASE("[String]: CaseConvTest") {
  REQUIRE(boost::to_lower_copy("ABC"s) == "abc");
  REQUIRE(boost::to_upper_copy("abc"s) == "ABC");
}
