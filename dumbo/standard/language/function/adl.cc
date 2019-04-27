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
 * @file: adl.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_...

#include <iostream>  // for operator<<, cout, endl, ostream
#include <string>    // for string, allocator, basic_string

TEST_CASE("[Adl]: simple test") {
  std::cout << "Test\n";            // There is no operator<< in global namespace, but ADL
                                    // examines std namespace because the left argument is in
                                    // std and finds std::operator<<(std::ostream&, const char*)
  operator<<(std::cout, "Test\n");  // same, using function call notation

  // however,
  // Error: 'endl' is not declared in this namespace.
  // This is not a function call to endl(), so ADL does not apply
  // std::cout << endl;

  endl(std::cout);  // OK: this is a function call: ADL examines std namespace
                    // because the argument of endl is in std, and finds std::endl

  // Error: 'endl' is not declared in this namespace.
  // The sub-expression (endl) is not a function call expression
  // (endl)(std::cout);
}

namespace unnamed_namespace {
using std::string;
bool operator==(const string&, string&) { return true; }
}  // namespace unnamed_namespace

TEST_CASE("[Adl]: operator overload") {
  unnamed_namespace::string a = "123", b = "234";
  REQUIRE(unnamed_namespace::operator==(a, b));
  // TODO(curoky): make equal
  REQUIRE(a != b);
}
