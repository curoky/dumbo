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
#include <folly/FBString.h>

#include <string>

TEST_CASE("[String]: sizeof") {
  REQUIRE(sizeof("12345") == 6);
  REQUIRE(sizeof("0123456789") == 11);
  REQUIRE(sizeof(std::string("12345")) == 32);
  REQUIRE(sizeof(std::string("0123456789")) == 32);
  REQUIRE(sizeof(folly::fbstring("12345")) == 24);
  REQUIRE(sizeof(folly::fbstring("0123456789")) == 24);

  REQUIRE(alignof("12345") == 1);
  REQUIRE(alignof("0123456789") == 1);
  REQUIRE(alignof(std::string("12345")) == 8);
  REQUIRE(alignof(std::string("0123456789")) == 8);
  REQUIRE(alignof(folly::fbstring("12345")) == 8);
  REQUIRE(alignof(folly::fbstring("0123456789")) == 8);
}
