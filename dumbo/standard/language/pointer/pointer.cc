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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <stdint.h>  // for int64_t

#include <iostream>
#include <vector>  // for vector

TEST_CASE("[Pointer]: pointer transform") {
  std::vector<int> nubs = {1, 2, 3};
  const auto& nubs_ref = nubs;

  const void* nubs_void_pointer = &nubs_ref;
  int64_t p = (int64_t)nubs_void_pointer;

  const std::vector<int>* nubs_pointer = (const std::vector<int>*)p;

  REQUIRE(nubs_pointer->size() == 3);
}

TEST_CASE("[Pointer]: pointer postion") {
  int a;
  int b;
  int64_t c;
  char d;
  std::cout << &a << " " << &b << " " << &c << " " << &d << std::endl;
}
