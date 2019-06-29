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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <chrono>  // for filesystem
#include <filesystem>  // for path, operator==, operator/, operator<<, absolute, temp_directory_path, current_path
#include <string>  // for basic_string

namespace fs = std::filesystem;

TEST_CASE("[Path]: base test") {
  fs::path now_path = fs::current_path();
  fs::path sandbox = "sandbox/a/b/c";

  REQUIRE(fs::absolute(sandbox) == now_path / sandbox);

  fs::path abs_sandbox = fs::absolute(sandbox);
  REQUIRE(abs_sandbox.root_path() == "/");
  REQUIRE(abs_sandbox.root_directory() == "/");
  REQUIRE(abs_sandbox.root_name() == "");
  REQUIRE(abs_sandbox.parent_path() == now_path / "sandbox" / "a" / "b");
  REQUIRE(sandbox.relative_path() == sandbox);
}

TEST_CASE("[Path]: TempPach") { REQUIRE(fs::temp_directory_path() == "/tmp"); }
