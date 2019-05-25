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
 * @file: cow_string_test.cc
 * ----------------------------------------------------------------------------
 */

#include "cow_string.h"

#include <catch2/catch.hpp>

TEST_CASE("[CowString]: basic usage") {
  cry::CowString str(5, 'a');
  REQUIRE(str.use_count() == 1);
  REQUIRE(str.data() == std::string("aaaaa"));

  cry::CowString str_cp = str;
  REQUIRE(str.use_count() == 2);
  REQUIRE(str_cp.use_count() == 2);

  str_cp[0] = 'b';
  REQUIRE(str_cp.use_count() == 1);
  REQUIRE(str_cp.data() == std::string("baaaa"));
}
