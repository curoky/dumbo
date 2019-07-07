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

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, TEST_CASE, REQUIRE_THROWS_AS
#include <fmt/chrono.h>      // IWYU pragma: keep
#include <fmt/format.h>  // for format, arg, operator""_a, parse_nonnegative_int, join, udl_arg, operator""_format, print, format_to, udl_formatter, FMT_STRING, format_error, literals
#include <fmt/printf.h>  // IWYU pragma: keep

#include <ctime>     // for localtime, time, time_t
#include <iterator>  // for back_insert_iterator, back_inserter
#include <string>    // for operator==, basic_string, string
#include <vector>    // for vector

TEST_CASE("[Fmt]: print test") {
  fmt::print("Hello, {}!", "world");   // Python-like format string syntax
  fmt::printf("Hello, %s!", "world");  // printf format string syntax
}

TEST_CASE("[Fmt]: format test") {
  REQUIRE(fmt::format("{}-{}-{}", "1", "2", "3") == "1-2-3");
  REQUIRE(fmt::format("{0}-{1}-{2}", "1", "2", "3") == "1-2-3");
  REQUIRE(fmt::format("{0}-{0}-{0}", "1", "2", "3") == "1-1-1");
  REQUIRE(fmt::format("{2}-{1}-{0}", "1", "2", "3") == "3-2-1");

  REQUIRE(fmt::format("{a}-{b}-{c}", fmt::arg("a", 1), fmt::arg("b", "2"), fmt::arg("c", 3)) ==
          "1-2-3");
  using namespace fmt::literals;  // NOLINT
  REQUIRE(fmt::format("{a}-{b}-{c}", "a"_a = 1, "b"_a = "2", "c"_a = 3) == "1-2-3");
  REQUIRE("{}"_format(1) == "1");
}

TEST_CASE("[Fmt]: except test") {
  REQUIRE_THROWS_AS(fmt::format("The answer is {:d}", "forty-two"), fmt::format_error);

  // A compile-time error because 'd' is an invalid specifier for strings.
  // fmt::format(FMT_STRING("The answer is {:d}"), "forty-two");
  fmt::format(FMT_STRING("The answer is {:d}"), 42);
}

TEST_CASE("[Fmt]: output iterator support") {
  // std::vector<char> out;
  std::string out;
  fmt::format_to(std::back_inserter(out), "{}", 42);
  REQUIRE(out == "42");
}

TEST_CASE("[Fmt]: join") {
  std::vector<int> v = {1, 2, 3};
  REQUIRE(fmt::format("{}", fmt::join(v, ", ")) == "1, 2, 3");
}

TEST_CASE("[Fmt]: date and time formatting") {
  std::time_t t = std::time(nullptr);
  // Prints "The date is 2016-04-29." (with the current date)
  fmt::print("The date is {:%Y-%m-%d}.", *std::localtime(&t));
}
