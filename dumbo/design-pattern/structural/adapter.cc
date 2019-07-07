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
class Lion {
 public:
  virtual void roar() = 0;
};

class AfricanLion : public Lion {
 public:
  void roar() override { std::cout << "I'am african lion" << std::endl; }
};

class AsianLion : public Lion {
 public:
  void roar() override { std::cout << "I'am asian lion" << std::endl; }
};

class Hunter {
 public:
  void hunt(Lion& lion) { lion.roar(); }
};

// This needs to be added to the game
class WildDog {
 public:
  void bark() { std::cout << "I'am dog" << std::endl; }
};

class WildDogAdapter : public Lion {
 public:
  explicit WildDogAdapter(const WildDog& dog) : dog_(dog) {}

  void roar() override { dog_.bark(); }

 private:
  WildDog dog_;
};
}  // namespace
TEST_CASE("[Adapter]: ") {
  WildDog dog;
  WildDogAdapter dog_adapter(dog);
  Hunter hunter;
  hunter.hunt(dog_adapter);
}
