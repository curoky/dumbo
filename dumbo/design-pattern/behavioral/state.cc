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
#include <ctype.h>           // for tolower, toupper

#include <iostream>  // for endl, basic_ostream, cout, ostream
#include <memory>    // for allocator, make_shared, shared_ptr, __shared_ptr_access
#include <string>    // for string, operator<<, transform

namespace {
class IWritingState {
 public:
  virtual void Write(std::string words) = 0;
  virtual ~IWritingState() {}
};

class UpperCase : public IWritingState {
  void Write(std::string words) override {
    std::transform(words.begin(), words.end(), words.begin(), ::toupper);
    std::cout << words << std::endl;
  }
};

class LowerCase : public IWritingState {
  void Write(std::string words) override {
    std::transform(words.begin(), words.end(), words.begin(), ::tolower);
    std::cout << words << std::endl;
  }
};

class Default : public IWritingState {
  void Write(std::string words) override { std::cout << words << std::endl; }
};

class TextEditor {
 public:
  explicit TextEditor(const std::shared_ptr<IWritingState>& state) : state_(state) {}
  void SetState(const std::shared_ptr<IWritingState>& state) { state_ = state; }
  void Type(std::string words) { state_->Write(words); }

 private:
  std::shared_ptr<IWritingState> state_;
};
}  // namespace

TEST_CASE("[State]: ") {
  TextEditor editor(std::make_shared<Default>());
  editor.Type("First line");

  editor.SetState(std::make_shared<UpperCase>());
  editor.Type("Second line");
  editor.Type("Third line");

  editor.SetState(std::make_shared<LowerCase>());
  editor.Type("Fourth line");
  editor.Type("Fifth line");
}
