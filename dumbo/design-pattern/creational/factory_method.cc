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
 */

#include <catch2/catch.hpp>

#include <iostream>

namespace {
class Interviewer {
 public:
  virtual void ask_questions() = 0;
  virtual ~Interviewer() = default;
};

class Developer : public Interviewer {
 public:
  void ask_questions() override { std::cout << "Asking about design patterns!" << std::endl; }
};

class CommunityExecutive : public Interviewer {
 public:
  void ask_questions() override { std::cout << "Asking about community building" << std::endl; }
};

class HiringManager {
 public:
  void takeInterview() {
    auto iv = make_interviewer();
    iv->ask_questions();
    delete iv;
  }
  virtual ~HiringManager() = default;

 private:
  virtual Interviewer* make_interviewer() = 0;
};

class DevelopmentManager : public HiringManager {
 public:
  Interviewer* make_interviewer() override { return new Developer(); }
};

class MarketingManager : public HiringManager {
 public:
  Interviewer* make_interviewer() override { return new CommunityExecutive(); }
};
}  // namespace

TEST_CASE("[FactoryMethod]: ") {
  auto dev_manager = new DevelopmentManager();
  dev_manager->takeInterview();  // Output: Asking about design patterns

  auto mk_manager = new MarketingManager();
  mk_manager->takeInterview();  // Output: Asking about community building.

  delete dev_manager;
  delete mk_manager;
}
