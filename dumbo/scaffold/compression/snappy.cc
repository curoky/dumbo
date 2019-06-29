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

#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE
#include <snappy.h>  // for Compress, Uncompress

#include <string>  // for basic_string, string, operator==, allocator

// https://github.com/google/snappy/blob/master/README.md

TEST_CASE("[Snappy]: compression and decompress") {
  std::string data = "hello world";
  std::string compressed;
  std::string decompressed;

  snappy::Compress(data.data(), data.size(), &compressed);
  snappy::Uncompress(compressed.data(), compressed.size(), &decompressed);

  REQUIRE(decompressed == data);
}
