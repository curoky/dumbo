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
 * @file: container.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <tbb/concurrent_vector.h>  // for concurrent_vector
#include <tbb/tbb_allocator.h>      // for tbb_allocator

#define TBB_PREVIEW_CONCURRENT_ORDERED_CONTAINERS 1
#include <tbb/concurrent_map.h>  // for concurrent_map
#include <tbb/concurrent_set.h>  // for concurrent_set

#include <utility>  // for move

TEST_CASE("[Container]: concurrent_vector") {
  tbb::concurrent_vector<int> nub;
  nub.emplace_back(1);
  REQUIRE(nub.size() == 1);
}

TEST_CASE("[Container]: concurrent_map") {
  tbb::concurrent_map<int, int> nub;
  nub[1] = 1;
  REQUIRE(nub[1] == 1);
}

TEST_CASE("[Container]: concurrent_set") {
  tbb::concurrent_set<int> nub;
  nub.insert(1);
  REQUIRE(nub.count(1) == 1);
}
