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

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, REQUIRE_FALSE, TEST_CASE, REQUIRE_THROWS_AS
#include <folly/FileUtil.h>  // for readFile

#include <chrono>      // for filesystem
#include <filesystem>  // for create_directory, remove_all, remove, exists, create_directories, is_directory, is_regular_file, begin, copy, copy_file, directory_iterator, end, operator!=, recursive_directory_iterator, filesystem_error, copy_options, copy_options::recursive
#include <fstream>     // for basic_ofstream
#include <iosfwd>      // for ofstream
#include <string>      // for string, operator==, basic_string
#include <system_error>  // for error_code

namespace fs = std::filesystem;

TEST_CASE("[Directory]: CreateRemoveTest") {
  // 有第二个参数失败不抛异常
  std::error_code code;

  REQUIRE_FALSE(fs::exists("/tmp/sandbox"));
  REQUIRE_FALSE(fs::exists("/tmp/sandbox/a/b"));

  REQUIRE(fs::create_directory("/tmp/sandbox"));
  // 父目录不存在时创建失败
  REQUIRE_THROWS_AS(fs::create_directory("/tmp/sandbox/a/b"), fs::filesystem_error);
  REQUIRE_FALSE(fs::create_directory("/tmp/sandbox/a/b", code));

  // 递归创建目录
  REQUIRE(fs::create_directories("/tmp/sandbox/a/b"));

  // 目录非空时删除失败
  REQUIRE_THROWS_AS(fs::remove("/tmp/sandbox/a"), fs::filesystem_error);
  REQUIRE_FALSE(fs::remove("/tmp/sandbox/a", code));
  REQUIRE(fs::remove("/tmp/sandbox/a/b", code));
  REQUIRE(fs::remove_all("/tmp/sandbox"));
}

TEST_CASE("[Directory]: WalkTest") {
  fs::create_directories("/tmp/sandbox/a/b");
  std::ofstream("/tmp/sandbox/file1.txt");
  std::ofstream("/tmp/sandbox/file2.txt");
  std::ofstream("/tmp/sandbox/a/file1.txt");
  std::ofstream("/tmp/sandbox/a/file2.txt");

  int cnt = 0;
  for (auto& p : fs::directory_iterator("/tmp/sandbox")) {
    (void)p, cnt++;
  }
  REQUIRE(cnt == 3);
  cnt = 0;
  for (auto& p : fs::recursive_directory_iterator("/tmp/sandbox")) {
    (void)p, cnt++;
  }
  REQUIRE(cnt == 6);

  fs::remove_all("/tmp/sandbox");
}

TEST_CASE("[Directory]: CopyTest") {
  fs::create_directory("/tmp/sandbox");
  std::ofstream("/tmp/sandbox/file1.txt").put('a');
  fs::copy_file("/tmp/sandbox/file1.txt", "/tmp/sandbox/file2.txt");

  std::string content;
  folly::readFile("/tmp/sandbox/file1.txt", content);
  REQUIRE(content == "a");
  folly::readFile("/tmp/sandbox/file2.txt", content);
  REQUIRE(content == "a");

  // fail to copy directory
  fs::create_directory("/tmp/sandbox/abc");
  REQUIRE_THROWS_AS(fs::copy_file("/tmp/sandbox/abc", "/tmp/sandbox/def"), fs::filesystem_error);

  fs::create_directories("/tmp/sandbox/a/b");

  // 仅copy一层目录
  fs::copy("/tmp/sandbox", "/tmp/sandbox2");

  fs::remove_all("/tmp/sandbox2");

  // 递归copy子目录
  fs::copy("/tmp/sandbox", "/tmp/sandbox2", std::filesystem::copy_options::recursive);

  fs::remove_all("/tmp/sandbox");
  fs::remove_all("/tmp/sandbox2");
}

TEST_CASE("[Directory]: JudgeTest") {
  fs::create_directory("/tmp/sandbox");
  std::ofstream("/tmp/sandbox/file1.txt");

  REQUIRE(fs::is_directory("/tmp/sandbox"));
  REQUIRE(fs::is_regular_file("/tmp/sandbox/file1.txt"));

  fs::remove_all("/tmp/sandbox");
}
