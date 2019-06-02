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
 * @file: scoped-enumerations.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

enum class Method : char {
  echo = 'e',
  ping = 'p',
};

TEST_CASE("enum class string") {
  Method m = Method::echo;
  REQUIRE(m == Method::echo);
}
