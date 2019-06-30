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

#include <catch2/catch.hpp>

#include <iostream>
#include <vector>
namespace {
class SortStrategy {
 public:
  virtual void sort(const std::vector<int>& dataset) = 0;
};

class BubbleSortStrategy : public SortStrategy {
  void sort(const std::vector<int>& dataset) override {
    (void)dataset;
    std::cout << "Sorting using bubble sort" << std::endl;
  }
};

class QuickSortStrategy : public SortStrategy {
  void sort(const std::vector<int>& dataset) override {
    (void)dataset;
    std::cout << "Sorting using quick sort" << std::endl;
  }
};

class Sorter {
 public:
  explicit Sorter(SortStrategy* sorter) : sorter_(sorter) {}

  void sort(const std::vector<int>& dataset) { return sorter_->sort(dataset); }

 public:
  SortStrategy* sorter_;
};
}  // namespace
TEST_CASE("[Strategy]: ") {
  const std::vector<int>& dataset = {1, 5, 4, 3, 2, 8};
  BubbleSortStrategy bubble;
  QuickSortStrategy quick;

  Sorter bubble_sorter(&bubble);
  bubble_sorter.sort(dataset);  // Output : Sorting using bubble sort

  Sorter quick_sorter(&quick);
  quick_sorter.sort(dataset);  // Output : Sorting using quick sort
}
