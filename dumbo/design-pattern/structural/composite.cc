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
#include <string>
#include <vector>

namespace {

class Employee {
 public:
  Employee(const std::string& name, float salary) : name_(name), salary_(salary) {}
  virtual std::string GetName() { return name_; }
  virtual float GetSalary() { return salary_; }
  virtual ~Employee() {}

 protected:
  std::string name_;
  float salary_;
};

class Developer : public Employee {
 public:
  Developer(const std::string& name, float salary) : Employee(name, salary) {}
};

class Designer : public Employee {
 public:
  Designer(const std::string& name, float salary) : Employee(name, salary) {}
};

class Organization {
 public:
  void AddEmployee(const Employee& employee) { employees_.push_back(employee); }
  float GetNetSalaries() {
    float net_salary = 0;
    for (auto& employee : employees_) {
      net_salary += employee.GetSalary();
    }
    return net_salary;
  }

 private:
  std::vector<Employee> employees_;
};

}  // namespace

TEST_CASE("[Composite]: ") {
  Developer john("John Doe", 12000);
  Designer jane("Jane Doe", 15000);

  Organization org;
  org.AddEmployee(john);
  org.AddEmployee(jane);

  std::cout << "Net salaries: " << org.GetNetSalaries() << std::endl;
}
