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
#include <cxxabi.h>          // for __forced_unwind

#include <ctime>     // for localtime, time, time_t
#include <iomanip>   // for operator<<, put_time
#include <iostream>  // for operator<<, basic_ostream, endl, cout, ostream
#include <string>    // for string, allocator, operator<<, char_traits

namespace {
class User;

class ChatRoomMediator {
 public:
  virtual void ShowMessage(const User& user, const std::string& message) = 0;
};

class ChatRoom : public ChatRoomMediator {
 public:
  void ShowMessage(const User& user, const std::string& message) override;
};

class User {
 public:
  User(const std::string& name, ChatRoomMediator& chatMediator)
      : name_(name), chatMediator_(chatMediator) {}
  const std::string& GetName() const { return name_; }
  void Send(const std::string& message) { chatMediator_.ShowMessage(*this, message); }

 private:
  std::string name_;
  ChatRoomMediator& chatMediator_;
};

void ChatRoom::ShowMessage(const User& user, const std::string& message) {
  std::time_t now = std::time(nullptr);
  std::cout << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "[" << user.GetName()
            << "]: " << message << std::endl;
}
}  // namespace
TEST_CASE("[Mediator]: ") {
  ChatRoom mediator;
  User john("John Doe", mediator);
  User jane("Jane Doe", mediator);
  john.Send("Hi, there!");
  jane.Send("Hey!");
}
