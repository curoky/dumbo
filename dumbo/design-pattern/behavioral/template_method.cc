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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE

#include <iostream>  // for operator<<, endl, basic_ostream, cout, ostream

namespace {
class Builder {
 public:
  void Build() {
    Test();
    Lint();
    Assemble();
    Deploy();
  }

 protected:
  virtual void Test() = 0;
  virtual void Lint() = 0;
  virtual void Assemble() = 0;
  virtual void Deploy() = 0;
};

class AndroidBuilder : public Builder {
  void Test() override { std::cout << "Running android tests" << std::endl; }
  void Lint() override { std::cout << "Linting the android code" << std::endl; }
  void Assemble() override { std::cout << "Assembling the android build" << std::endl; }
  void Deploy() override { std::cout << "Deploying android build to server" << std::endl; }
};

class IosBuilder : public Builder {
  void Test() override { std::cout << "Running ios tests" << std::endl; }
  void Lint() override { std::cout << "Linting the ios code" << std::endl; }
  void Assemble() override { std::cout << "Assembling the ios build" << std::endl; }
  void Deploy() override { std::cout << "Deploying ios build to server" << std::endl; }
};
}  // namespace
TEST_CASE("[TemplateMethod]: ") {
  AndroidBuilder androidBuilder;
  androidBuilder.Build();

  IosBuilder iosBuilder;
  iosBuilder.Build();
}
