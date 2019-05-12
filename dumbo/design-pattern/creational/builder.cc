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
 * @file: builder.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>

#include <iostream>

namespace {
class Burger {
 public:
  class BurgerBuilder;
  void showFlavors() {
    std::cout << size_;
    if (cheese_) std::cout << "-cheese";
    if (peperoni_) std::cout << "-peperoni";
    if (lettuce_) std::cout << "-lettuce";
    if (tomato_) std::cout << "-tomato";
    std::cout << std::endl;
  }

 private:
  explicit Burger(int size) : size_(size) {}

  int size_ = 7;
  bool cheese_ = false;
  bool peperoni_ = false;
  bool lettuce_ = false;
  bool tomato_ = false;
};

class Burger::BurgerBuilder {
 public:
  explicit BurgerBuilder(int size) { burger_ = new Burger(size); }
  BurgerBuilder& AddCheese() {
    burger_->cheese_ = true;
    return *this;
  }
  BurgerBuilder& AddPepperoni() {
    burger_->peperoni_ = true;
    return *this;
  }
  BurgerBuilder& AddLettuce() {
    burger_->lettuce_ = true;
    return *this;
  }
  BurgerBuilder& AddTomato() {
    burger_->tomato_ = true;
    return *this;
  }
  Burger* Build() { return burger_; }

 private:
  Burger* burger_;
};
}  // namespace

TEST_CASE("[Builder]: ") {
  Burger* burger = Burger::BurgerBuilder(14).AddPepperoni().AddLettuce().AddTomato().Build();
  burger->showFlavors();

  delete burger;
}
