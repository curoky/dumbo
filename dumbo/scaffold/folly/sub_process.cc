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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, Section, TEST_CASE, CAPTURE, Capturer, SECTION
#include <folly/Subprocess.h>  // for ProcessReturnCode, Subprocess, Subprocess::Options

#include <map>     // for pair
#include <string>  // for string, operator==, allocator, basic_string
#include <vector>  // for vector

TEST_CASE("[SubProcess]: basic usage") {
  std::vector<std::string> args = {"/bin/ls", "-la"};
  folly::Subprocess proc(args);
  folly::ProcessReturnCode code = proc.wait();
  REQUIRE(code.exited() == true);
  REQUIRE(code.exitStatus() == 0);
}

TEST_CASE("[SubProcess]: terminate/kill process") {
  std::vector<std::string> args = {"/bin/sleep", "5"};
  folly::Subprocess proc(args);

  REQUIRE(proc.returnCode().running() == true);

  SECTION("kill") {
    proc.kill();
    folly::ProcessReturnCode code = proc.wait();
    CAPTURE(code.str());  // killed by signal 9
    REQUIRE(code.killed() == true);
  }

  SECTION("terminate") {
    proc.terminate();
    folly::ProcessReturnCode code = proc.wait();
    CAPTURE(code.str());  // killed by signal 15
    REQUIRE(code.killed() == true);
  }
}

TEST_CASE("[SubProcess]: output") {
  std::vector<std::string> args = {"/bin/echo", "hello world"};
  folly::Subprocess proc(args, folly::Subprocess::Options().pipeStdout().pipeStderr());

  auto p = proc.communicate();
  REQUIRE(p.first == "hello world\n");

  folly::ProcessReturnCode code = proc.wait();
  REQUIRE(code.exited() == true);
  REQUIRE(code.exitStatus() == 0);
}

TEST_CASE("[SubProcess]: pipe") {
  // std::vector<std::string> args = {"/bin/echo", "hello world" };
  std::string args = "echo '3\n2\n1' | sort | xargs";
  folly::Subprocess proc(args, folly::Subprocess::Options().pipeStdout().pipeStderr());

  auto p = proc.communicate();
  REQUIRE(p.first == "1 2 3\n");

  folly::ProcessReturnCode code = proc.wait();
  REQUIRE(code.exited() == true);
  REQUIRE(code.exitStatus() == 0);
}
