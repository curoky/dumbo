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
 * @file: prototype.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE

#include <string>  // for string, allocator

namespace {
class Sheep {
 public:
  explicit Sheep(const std::string& name) : name_(name) {
    // sleep 100s;
  }
  Sheep(const Sheep& s) { name_ = s.name_; }
  void set_name(const std::string& name) { name_ = name; }

 private:
  std::string name_;
};
}  // namespace
TEST_CASE("[Prototype]: ") {
  Sheep jolly("Jolly");

  Sheep dolly(jolly);  // copy constructor
  dolly.set_name("Dolly");
}
