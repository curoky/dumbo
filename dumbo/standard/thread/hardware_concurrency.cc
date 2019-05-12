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
 * @file: hardware_concurrency.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>
#include <folly/system/HardwareConcurrency.h>

#include <thread>

TEST_CASE("[HardwareConcurrency]: basic usage") {
  unsigned int n1 = std::thread::hardware_concurrency();
  unsigned int n2 = folly::hardware_concurrency();
  REQUIRE(n1 == n2);
}