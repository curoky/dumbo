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

#include <iostream>  // for endl, cout, ostream, basic_ostream, basic_ostream<>::__ostream_type
#include <string>    // for operator<<, operator+, allocator, string

namespace {
class ICoffee {
 public:
  virtual float GetCost() = 0;
  virtual std::string GetDescription() = 0;
  virtual ~ICoffee() = default;
};

class SimpleCoffee : public ICoffee {
 public:
  float GetCost() override { return 10; }
  std::string GetDescription() override { return "Simple coffee"; }
};

class CoffeePlus : public ICoffee {
 public:
  explicit CoffeePlus(ICoffee& coffee) : coffee_(coffee) {}
  virtual float GetCost() = 0;
  virtual std::string GetDescription() = 0;

 protected:
  ICoffee& coffee_;
};

class MilkCoffee : public CoffeePlus {
 public:
  explicit MilkCoffee(ICoffee& coffee) : CoffeePlus(coffee) {}
  float GetCost() override { return coffee_.GetCost() + 2; }
  std::string GetDescription() override { return coffee_.GetDescription() + ", milk"; }
};

class WhipCoffee : public CoffeePlus {
 public:
  explicit WhipCoffee(ICoffee& coffee) : CoffeePlus(coffee) {}
  float GetCost() override { return coffee_.GetCost() + 5; }
  std::string GetDescription() override { return coffee_.GetDescription() + ", whip"; }
};

class VanillaCoffee : public CoffeePlus {
 public:
  explicit VanillaCoffee(ICoffee& coffee) : CoffeePlus(coffee) {}
  float GetCost() override { return coffee_.GetCost() + 3; }
  std::string GetDescription() override { return coffee_.GetDescription() + ", vanilla"; }
};
}  // namespace

TEST_CASE("[Decorator]: ") {
  ICoffee* someCoffee = new SimpleCoffee();
  std::cout << someCoffee->GetCost() << std::endl;         // 10
  std::cout << someCoffee->GetDescription() << std::endl;  // Simple coffee

  ICoffee* newCoffee;

  newCoffee = new MilkCoffee(*someCoffee);
  std::cout << newCoffee->GetCost() << std::endl;         // 12
  std::cout << newCoffee->GetDescription() << std::endl;  // Simple coffee, milk
  delete newCoffee;

  newCoffee = new WhipCoffee(*someCoffee);
  std::cout << newCoffee->GetCost() << std::endl;         // 17
  std::cout << newCoffee->GetDescription() << std::endl;  // Simple coffee, milk, whip
  delete newCoffee;

  newCoffee = new VanillaCoffee(*someCoffee);
  std::cout << newCoffee->GetCost() << std::endl;         // 20
  std::cout << newCoffee->GetDescription() << std::endl;  // Simple coffee, milk, whip, vanilla
  delete newCoffee;

  delete someCoffee;
}
