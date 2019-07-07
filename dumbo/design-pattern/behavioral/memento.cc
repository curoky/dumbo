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

#include <iostream>  // for endl, basic_ostream, cout, ostream
#include <memory>    // for allocator, make_shared, __shared_ptr_access, shared_ptr
#include <string>    // for string, operator<<, operator+

namespace {
class EditorMemento {
 public:
  explicit EditorMemento(const std::string& content) : content_(content) {}
  const std::string& GetContent() const { return content_; }

 private:
  std::string content_;
};

class Editor {
  using MementoType = std::shared_ptr<EditorMemento>;

 public:
  void Type(const std::string& words) { content_ += " " + words; }
  const std::string& GetContent() const { return content_; }
  MementoType Save() { return std::make_shared<EditorMemento>(content_); }
  void Restore(MementoType memento) { content_ = memento->GetContent(); }

 private:
  std::string content_;
};
}  // namespace

TEST_CASE("[Memento]: ") {
  Editor editor;
  //! Type some stuff
  editor.Type("This is the first sentence.");
  editor.Type("This is second.");
  //! Save the state to restore to : This is the first sentence. This is second.
  auto saved = editor.Save();
  //! Type some more
  editor.Type("And this is third.");
  std::cout << editor.GetContent() << std::endl;
  editor.Restore(saved);
  std::cout << editor.GetContent() << std::endl;
}
