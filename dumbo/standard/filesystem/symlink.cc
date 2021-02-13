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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <chrono>      // for filesystem
#include <filesystem>  // for read_symlink, operator<<, operator==, path, directory_iterator, begin, create_directories, create_directory_symlink, create_symlink, directory_entry, end, is_symlink, operator!=, remove_all
#include <iostream>    // for operator<<, basic_ostream, cout, ostream
#include <sstream>  // for basic_stringbuf<>::int_type, basic_stringbuf<>::pos_type, basic_stringbuf<>::__streambuf_type
#include <string>  // for char_traits, basic_string

namespace fs = std::filesystem;

TEST_CASE("[Symlink]: CreateTest") {
  fs::create_directories("/tmp/sandbox/subdir");
  fs::create_symlink("/tmp/target", "/tmp/sandbox/sym1");
  fs::create_directory_symlink("/tmp/subdir", "/tmp/sandbox/sym2");

  for (auto& p : fs::directory_iterator("/tmp/sandbox")) {
    if (fs::is_symlink(p.symlink_status())) {
      std::cout << p.path() << "->" << fs::read_symlink(p.path()) << '\n';
    }
  }
  REQUIRE(fs::read_symlink("/tmp/sandbox/sym1") == "/tmp/target");
  REQUIRE(fs::read_symlink("/tmp/sandbox/sym2") == "/tmp/subdir");

  fs::remove_all("/tmp/sandbox");
}
