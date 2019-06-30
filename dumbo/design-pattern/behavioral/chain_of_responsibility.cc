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

#include <iostream>  // for operator<<, basic_ostream, endl, cout, ostream, basic_ostream<>::__ostream_type
#include <string>  // for string, allocator, operator<<, char_traits

namespace {
class Account {
 public:
  explicit Account(float balance) : balance_(balance) {}
  virtual std::string GetClassName() { return "Account"; }
  void SetNext(Account* const account) { successor_ = account; }
  bool CanPay(float amount) { return balance_ >= amount; }
  void Pay(float amountToPay) {
    if (CanPay(amountToPay)) {
      std::cout << "Paid " << amountToPay << " using " << GetClassName() << std::endl;
    } else if (successor_) {
      std::cout << "Cannot pay using " << GetClassName() << ". Proceeding..." << std::endl;
      successor_->Pay(amountToPay);
    } else {
      throw "None of the accounts have enough balance.";
    }
  }

 protected:
  Account* successor_ = nullptr;
  float balance_;
};

class Bank : public Account {
 public:
  explicit Bank(float balance) : Account(balance) {}
  std::string GetClassName() override { return "Bank"; }
};

class Paypal : public Account {
 public:
  explicit Paypal(float balance) : Account(balance) {}
  std::string GetClassName() override { return "Paypal"; }
};

class Bitcoin : public Account {
 public:
  explicit Bitcoin(float balance) : Account(balance) {}
  std::string GetClassName() override { return "Bitcoin"; }
};
}  // namespace
TEST_CASE("[ChainOfResponsibility]: ") {
  //! Let's prepare a chain like below:
  //! bank -> paypal -> bitcoin
  //! First priority bank
  //!   If bank can't pay then paypal
  //!   If paypal can't pay then bit coin

  Bank bank(100);        //> Bank with balance 100
  Paypal paypal(200);    //> Paypal with balance 200
  Bitcoin bitcoin(300);  //> Bitcoin with balance 300

  bank.SetNext(&paypal);
  paypal.SetNext(&bitcoin);

  bank.Pay(259);
}
