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
#include <string>    // for allocator, operator==, string

namespace {
class IDoor {
 public:
  virtual void Open() = 0;
  virtual void Close() = 0;
};

class LabDoor : public IDoor {
 public:
  void Open() override { std::cout << "Opening lab door" << std::endl; }
  void Close() override { std::cout << "Closing the lab door" << std::endl; }
};

class Security {
 public:
  explicit Security(IDoor& door) : door_(door) {}
  bool Authenticate(const std::string& password) { return password == "$ecr@t"; }
  void Open(const std::string& password) {
    if (Authenticate(password)) {
      door_.Open();
    } else {
      std::cout << "Big no! It ain't possible." << std::endl;
    }
  }
  void Close() { door_.Close(); }

 private:
  IDoor& door_;
};
}  // namespace
TEST_CASE("[Proxy]: ") {
  LabDoor labDoor;
  Security securityDoor(labDoor);
  securityDoor.Open("invalid");
  securityDoor.Open("$ecr@t");
  securityDoor.Close();
}
