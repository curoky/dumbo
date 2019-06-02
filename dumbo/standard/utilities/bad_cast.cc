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
 * @file: bad_cast.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, operator""_catch_sr, AssertionHandler, REQUIRE_THROWS_AS

#include <typeinfo>  // for bad_cast

struct Foo {
  virtual ~Foo() {}
};
struct Bar {
  virtual ~Bar() {}
};

TEST_CASE("bad cast") {
  Bar b;
  REQUIRE_THROWS_AS(dynamic_cast<Foo&>(b), std::bad_cast);
}