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
 * @file: file_util.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, StartsWith, REQUIRE, REQUIRE_THAT, TEST_CASE
#include <folly/FBString.h>  // for fbstring
#include <folly/FileUtil.h>  // for readFile
#include <stdlib.h>          // for free
#include <memory>            // for allocator

TEST_CASE("[FileUtil]: read file") {
  folly::fbstring content;
  bool status = folly::readFile("/proc/sys/kernel/ostype", content);
  REQUIRE(status == true);
  REQUIRE_THAT(content.toStdString(), Catch::StartsWith("Linux"));

  // file not found
  status = folly::readFile("/proc/sys/kernel/ostype.2333", content);
  REQUIRE(status == false);
}
