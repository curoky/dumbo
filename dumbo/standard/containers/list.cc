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
 * @file: list.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

#include <list>

TEST_CASE("[List]: erase") {
  std::list<int> nubs = {1, 2, 3, 4};
  auto iter = nubs.begin();
  iter = nubs.erase(iter);
  REQUIRE(*iter == 2);
}