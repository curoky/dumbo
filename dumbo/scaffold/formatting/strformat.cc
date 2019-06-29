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
 * @file: strformat.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>           // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <string>                     // for operator==, string, basic_string

#include "absl/strings/str_format.h"  // for StrFormat, FormatCountCapture

TEST_CASE("[Strformat]: basic usage") {
  // Characters
  REQUIRE(absl::StrFormat("%c", 'a') == "a");
  REQUIRE(absl::StrFormat("%c", 32) == " ");
  REQUIRE(absl::StrFormat("%c", 100) == "d");

  // Strings
  REQUIRE(absl::StrFormat("%s", "Hello!") == "Hello!");

  // Decimals
  REQUIRE(absl::StrFormat("%d", 1) == "1");
  REQUIRE(absl::StrFormat("%02d", 1) == "01");    // Zero-padding
  REQUIRE(absl::StrFormat("%-2d", 1) == "1 ");    // Left justification
  REQUIRE(absl::StrFormat("%0+3d", 1) == "+01");  // + specifier part of width

  // Octals
  REQUIRE(absl::StrFormat("%o", 16) == "20");
  REQUIRE(absl::StrFormat("%o", 016) == "16");    // literal octal
  REQUIRE(absl::StrFormat("%#o", 016) == "016");  // alternative form

  // Hex
  REQUIRE(absl::StrFormat("%x", 16) == "10");
  REQUIRE(absl::StrFormat("%x", 0x16) == "16");
  REQUIRE(absl::StrFormat("%#x", 0x16) == "0x16");  // alternative form
  REQUIRE(absl::StrFormat("%X", 10) == "A");        // Upper-case

  // Unsigned Integers
  REQUIRE(absl::StrFormat("%u", 16) == "16");
  REQUIRE(absl::StrFormat("%u", -16) == "4294967280");

  // Floating Point
  // Default precision of %f conversion is 6
  REQUIRE(absl::StrFormat("%f", 1.6) == "1.600000");  // Width includes decimal pt.
  REQUIRE(absl::StrFormat("%05.2f", 1.6) == "01.60");
  REQUIRE(absl::StrFormat("%.1f", 1.63232) == "1.6");    // Rounding down
  REQUIRE(absl::StrFormat("%.3f", 1.63451) == "1.635");  // Rounding up

  // Exponential Notation
  // Default precision of a %e conversion is 6
  // Default precision of exponent is 2
  // Default sign of exponent is +
  REQUIRE(absl::StrFormat("%e", 1.6) == "1.600000e+00");
  REQUIRE(absl::StrFormat("%1.1e", 1.6) == "1.6e+00");

  // Hex Exponents
  REQUIRE(absl::StrFormat("%a", 3.14159) == "0x1.921f9f01b866ep+1");

  // Floating Point to Exponential Notation
  REQUIRE(absl::StrFormat("%g", 31415900000) == "3.14159e+10");

  // Pointer conversion
  int n = 9;
  int* ptr = &n;
  // REQUIRE(absl::StrFormat("%p", ptr) == "0x7ffdeb6ad2a4");

  // Positional Modifiers
  std::string s = absl::StrFormat("%2$s, %3$s, %1$s!", "vici", "veni", "vidi");
  REQUIRE(s == "veni, vidi, vici!");

  {
    // Character Count Capturing
    int n = 0;
    std::string s = absl::StrFormat("%s%d%n", "hello", 123, absl::FormatCountCapture(&n));
    REQUIRE(8 == n);
  }
}

TEST_CASE("[Strformat]: type safety") {
  // REQUIRE(std::sprintf("%llx %d", 1, 2) == "1 2");
  REQUIRE(absl::StrFormat("%llx %d", 1, 2) == "1 2");
}
