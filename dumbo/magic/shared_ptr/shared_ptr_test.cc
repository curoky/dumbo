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

#include "shared_ptr.h"

#include <catch2/catch.hpp>

TEST_CASE("[SharedPtr]: basic usage") {
  cry::SharedPtr<int> ptr(new int(1));
  REQUIRE(ptr.use_count() == 1);
  ptr.reset();
  REQUIRE(ptr.get() == nullptr);
  REQUIRE(ptr.use_count() == 0);

  cry::SharedPtr<int> ptr2(new int(1));
  ptr = ptr2;
  REQUIRE(ptr.use_count() == 2);
  REQUIRE(ptr2.use_count() == 2);

  ptr2.reset();
  REQUIRE(ptr.use_count() == 1);
  ptr.reset();
  REQUIRE(ptr.get() == nullptr);
  REQUIRE(ptr.use_count() == 0);
}
