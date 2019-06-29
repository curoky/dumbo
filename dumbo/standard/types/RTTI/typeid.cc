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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <cstdint>   // for int16_t, int32_t, int64_t, int8_t
#include <string>    // for operator""s, operator==, basic_string, string_literals
#include <typeinfo>  // for type_info

using namespace std::string_literals;

TEST_CASE("[Typeid]: basic type") {
  REQUIRE(typeid(char).name() == "c"s);
  REQUIRE(typeid(signed char).name() == "a"s);
  REQUIRE(typeid(unsigned char).name() == "h"s);

  REQUIRE(typeid(bool).name() == "b"s);

  REQUIRE(typeid(int).name() == "i"s);
  REQUIRE(typeid(signed int).name() == "i"s);
  REQUIRE(typeid(unsigned int).name() == "j"s);

  REQUIRE(typeid(short).name() == "s"s);
  REQUIRE(typeid(short int).name() == "s"s);
  REQUIRE(typeid(long).name() == "l"s);
  REQUIRE(typeid(long long).name() == "x"s);

  REQUIRE(typeid(long int).name() == "l"s);
  REQUIRE(typeid(long long int).name() == "x"s);

  REQUIRE(typeid(float).name() == "f"s);
  REQUIRE(typeid(double).name() == "d"s);
  REQUIRE(typeid(long double).name() == "e"s);

  REQUIRE(typeid(int8_t).name() == "a"s);
  REQUIRE(typeid(int16_t).name() == "s"s);
  REQUIRE(typeid(int32_t).name() == "i"s);
  REQUIRE(typeid(int64_t).name() == "l"s);

  REQUIRE(typeid(const int).name() == "i"s);
  REQUIRE(typeid(int *).name() == "Pi"s);
  REQUIRE(typeid(int const *).name() == "PKi"s);
  REQUIRE(typeid(int *const).name() == "Pi"s);
  REQUIRE(typeid(int const *const).name() == "PKi"s);
  REQUIRE(typeid(int &).name() == "i"s);
  REQUIRE(typeid(const int &).name() == "i"s);
}
