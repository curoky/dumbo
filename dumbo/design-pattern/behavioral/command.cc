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

namespace {
class Bulb {
 public:
  void TurnOn() { std::cout << "Bulb has been lit" << std::endl; }
  void TurnOff() { std::cout << "Darkness!" << std::endl; }
};

class Command {
 public:
  virtual void Execute() = 0;
  virtual void Undo() = 0;
  virtual void Redo() = 0;
};

class TurnOn : public Command {
 public:
  explicit TurnOn(Bulb& bulb) : bulb_(bulb) {}
  void Execute() override { bulb_.TurnOn(); }
  void Undo() override { bulb_.TurnOff(); }
  void Redo() override { Execute(); }

 private:
  Bulb& bulb_;
};

class TurnOff : public Command {
 public:
  explicit TurnOff(Bulb& bulb) : bulb_(bulb) {}
  void Execute() override { bulb_.TurnOff(); }
  void Undo() override { bulb_.TurnOn(); }
  void Redo() override { Execute(); }

 private:
  Bulb& bulb_;
};

class RemoteControl {
 public:
  void Submit(Command& command) { command.Execute(); }
};
}  // namespace
TEST_CASE("[Command]: ") {
  Bulb bulb;
  TurnOn turnOn(bulb);
  TurnOff turnOff(bulb);

  RemoteControl control;
  control.Submit(turnOn);
  control.Submit(turnOff);
}
