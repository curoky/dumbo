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
 * @file: predefined_macros.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, EndsWith
#include <stdc-predef.h>  // for __STDC_ISO_10646__

#include <string>       // for basic_string, operator""s, operator==, allocator
#include <string_view>  // for literals

using namespace std::literals;

TEST_CASE("[PredefinedMacros]: simple test") {
  REQUIRE(__cplusplus == 201709L);
  REQUIRE(__STDC_HOSTED__ == 1);
  // standard/language/preprocessor/predefined_macros.cc
  REQUIRE_THAT(__FILE__, Catch::Matchers::EndsWith("predefined_macros.cc"));

  // REQUIRE(__LINE__ == 20);
  // REQUIRE(__DATE__ == "Dec  2 2019");
  // REQUIRE(__TIME__ == "21:57:42");
  REQUIRE(__STDCPP_DEFAULT_NEW_ALIGNMENT__ == 16);
  REQUIRE(__STDC__ == 1);
  // __STDC_VERSION__ was not declared in this scope
  // REQUIRE(__STDC_VERSION__ == "");
  REQUIRE(__STDC_ISO_10646__ == 201706L);
  // follow lines were not declared in this scope
  // REQUIRE(__STDC_MB_MIGHT_NEQ_WC__ == "");
  // REQUIRE(__STDCPP_STRICT_POINTER_SAFETY__ == "");
  // REQUIRE(__STDCPP_THREADS__ == "");
  REQUIRE(__FUNCTION__ == "____C_A_T_C_H____T_E_S_T____0"s);
  REQUIRE(__PRETTY_FUNCTION__ == "void ____C_A_T_C_H____T_E_S_T____0()"s);
  REQUIRE(__func__ == "____C_A_T_C_H____T_E_S_T____0"s);
}
