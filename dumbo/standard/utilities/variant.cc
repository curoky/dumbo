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
 * @file: variant.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, REQUI...

#include <string>   // for string, allocator
#include <variant>  // for get_if, holds_alternative, get, variant, bad_variant_access

TEST_CASE("[Variant]: GetTest") {
  std::variant<int, float> number = 3;
  REQUIRE(std::get<int>(number) == 3);
  REQUIRE(std::get<0>(number) == 3);

  REQUIRE_THROWS_AS(std::get<float>(number), std::bad_variant_access);
  //  std::get<double>(v); // compile error: no double in [int, float]
  //  std::get<3>(v);      // compile error: valid index values are 0 and 1

  REQUIRE(std::get_if<int>(&number));
  REQUIRE_FALSE(std::get_if<float>(&number));

  REQUIRE(std::get_if<0>(&number));
  REQUIRE_FALSE(std::get_if<1>(&number));
  // REQUIRE_FALSE(std::get_if<2>(&number)); // compile error: valid index values are 0 and 1
}

TEST_CASE("[Variant]: HoldAlternative") {
  std::variant<std::string, void const*> value;
  value = "123";
  REQUIRE(std::holds_alternative<void const*>(value));
  REQUIRE_FALSE(std::holds_alternative<std::string>(value));
  value = std::string("123");
  REQUIRE_FALSE(std::holds_alternative<void const*>(value));
  REQUIRE(std::holds_alternative<std::string>(value));
}
