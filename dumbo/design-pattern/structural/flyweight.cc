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

#include <iostream>  // for basic_ostream::operator<<, operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream
#include <memory>    // for unique_ptr, allocator, _MakeUniq<>::__single_object, make_unique
#include <string>    // for string, hash
#include <unordered_map>  // for unordered_map, _Node_iterator, operator!=, operator==, _Node_iterator_base, unordered_map<>::iterator, _Map_base<>::mapped_type, pair

namespace {
// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

class TeaMaker {
 public:
  KarakTea* Make(const std::string& preference) {
    if (availableTea_.find(preference) == availableTea_.end())
      availableTea_.insert({preference, std::make_unique<KarakTea>()});
    return availableTea_.at(preference).get();
  }

 private:
  std::unordered_map<std::string, std::unique_ptr<KarakTea>> availableTea_;
};

class TeaShop {
 public:
  explicit TeaShop(TeaMaker& teaMaker) : teaMaker_(teaMaker) {}
  void TakeOrder(const std::string& teaType, int table) {
    orders_[table] = teaMaker_.Make(teaType);
  }
  void Serve() {
    for (auto order : orders_) std::cout << "Serving tea to table# " << order.first << std::endl;
  }

 private:
  std::unordered_map<int, KarakTea*> orders_;
  TeaMaker& teaMaker_;
};
}  // namespace

TEST_CASE("[Flyweight]: ") {
  TeaMaker teaMaker;
  TeaShop shop(teaMaker);

  shop.TakeOrder("less sugar", 1);
  shop.TakeOrder("more milk", 2);
  shop.TakeOrder("without sugar", 5);

  shop.Serve();
}
