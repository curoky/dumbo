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
 * @file: optional.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE

#include <optional>  // for optional, operator==, nullopt, bad_optional_access, nullopt_t
#include <string>    // for string, basic_string, operator==

#include "dumbo/utilities/class_utils.h"

TEST_CASE("[Optional]: simple test") {
  std::optional<std::string> opt;
  REQUIRE(opt == std::nullopt);
  REQUIRE(opt.has_value() == false);
  REQUIRE(opt.value_or("123") == "123");
  REQUIRE_THROWS_AS(opt.value(), std::bad_optional_access);

  opt = "123";
  REQUIRE(opt.has_value() == true);
  REQUIRE(opt.value() == "123");
  REQUIRE(opt->size() == 3);
  REQUIRE((*opt).size() == 3);
}

TEST_CASE("[Optional]: ConstructTest") {
  using taro::util::ClassMetrics;

  std::optional<ClassMetrics> opt;
  opt = {};
}
