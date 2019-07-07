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

namespace {
class AnimalOperation;

// visitee
class Animal {
 public:
  virtual void Accept(AnimalOperation& operation) = 0;
};

class Dolphin;
class Lion;
class Monkey;

// visitor
class AnimalOperation {
 public:
  virtual void visitMonkey(Monkey& monkey) = 0;
  virtual void visitLion(Lion& lion) = 0;
  virtual void visitDolphin(Dolphin& dolphin) = 0;
};

class Monkey : public Animal {
 public:
  void Shout() { std::cout << "Ooh oo aa aa!" << std::endl; }
  void Accept(AnimalOperation& operation) override { operation.visitMonkey(*this); }
};

class Lion : public Animal {
 public:
  void Roar() { std::cout << "Roaaar!" << std::endl; }
  void Accept(AnimalOperation& operation) override { operation.visitLion(*this); }
};

class Dolphin : public Animal {
 public:
  void Speak() { std::cout << "Tuut tuttu tuutt!" << std::endl; }
  void Accept(AnimalOperation& operation) override { operation.visitDolphin(*this); }
};

class Speak : public AnimalOperation {
 public:
  void visitMonkey(Monkey& monkey) override { monkey.Shout(); }
  void visitLion(Lion& lion) override { lion.Roar(); }
  void visitDolphin(Dolphin& dolphin) override { dolphin.Speak(); }
};
}  // namespace

TEST_CASE("[Visitor]: ") {
  Monkey monkey;
  Lion lion;
  Dolphin dolphin;

  Speak speak;
  monkey.Accept(speak);
  lion.Accept(speak);
  dolphin.Accept(speak);
}
