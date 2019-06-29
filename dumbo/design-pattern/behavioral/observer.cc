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
#include <string>
#include <vector>

namespace {
class JobPost {
 public:
  explicit JobPost(const std::string& title) : title_(title) {}
  const std::string& getTitle() const { return title_; }

 private:
  std::string title_;
};

class Observer {
 public:
  virtual void onJobPosted(const JobPost& job) = 0;
};

class EmploymentAgency {
 public:
  void attach(Observer* observer) { observers.emplace_back(observer); }
  void addJob(const JobPost& job) { notify(job); }

 private:
  void notify(const JobPost& job) {
    for (auto ob : observers) {
      ob->onJobPosted(job);
    }
  }
  std::vector<Observer*> observers;
};

class JobSeeker : public Observer {
 public:
  explicit JobSeeker(const std::string& name) : name_(name) {}
  void onJobPosted(const JobPost& job) override {
    std::cout << "Hi " << name_ << "! New job posted: " << job.getTitle() << std::endl;
  }

 private:
  std::string name_;
};
}  // namespace

TEST_CASE("[Observer]: ") {
  JobSeeker johnDoe("John Doe");
  JobSeeker janeDoe("Jane Doe");
  EmploymentAgency jobPostings;
  jobPostings.attach(&johnDoe);
  jobPostings.attach(&janeDoe);
  jobPostings.addJob(JobPost("Software Enginner"));
}
