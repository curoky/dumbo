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
 * @file: murmurhash.cc
 * ----------------------------------------------------------------------------
 */

#include <MurmurHash3.h>  // for MurmurHash3_x64_128
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <stdint.h>  // for uint64_t

#include <string>  // for allocator, string

TEST_CASE("[Murmurhash]: basic usage") {
  std::string message = "helloworld";
  uint64_t output[2];
  MurmurHash3_x64_128(message.c_str(), message.size(), 0, output);
  REQUIRE(output[0] == 10256632503372987514ULL);
  REQUIRE(output[1] == 11724578221562109303ULL);
}
