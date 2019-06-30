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

#include <catch2/catch.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

// https://en.cppreference.com/w/cpp/language/string_literal

TEST_CASE("[StringLiteral]: Narrow multibyte string literal") {
  // " (unescaped_character|escaped_character)* "
  const char char_arr[] = "...";
}

TEST_CASE("[StringLiteral]: Wide string literal") {
  // L " (unescaped_character|escaped_character)* "
  const wchar_t wchar_arr[] = L"...";
}

TEST_CASE("[StringLiteral]: UTF-8 encoded string literal") {
  // u8 " (unescaped_character|escaped_character)* "
  // const char8_t utf8_arr[] = u8"..."; // c++2a
}

TEST_CASE("[StringLiteral]: UTF-16 encoded string literal") {
  // u " (unescaped_character|escaped_character)* "
  const char16_t utf16_arr[] = u"...";
}

TEST_CASE("[StringLiteral]: UTF-32 encoded string literal") {
  // U " (unescaped_character|escaped_character)* "
  const char32_t utf32_arr[] = U"...";
}

TEST_CASE("[StringLiteral]: Raw string literal") {
  // prefix(optional) R "delimiter( raw_characters )delimiter"
  const char nor_arr[] = "\0\0\0";
  const char raw_arr[] = R"~(\0\0\0)~";
  REQUIRE(sizeof(nor_arr) == 4);
  REQUIRE(sizeof(raw_arr) == 7);
}

#pragma GCC diagnostic pop
