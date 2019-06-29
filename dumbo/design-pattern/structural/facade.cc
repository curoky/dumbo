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
class Computer {
 public:
  void GetElectricShock() { std::cout << "Ouch!" << std::endl; }
  void MakeSound() { std::cout << "Beep beep!" << std::endl; }
  void ShowLoadingScreen() { std::cout << "Loading..." << std::endl; }
  void Bam() { std::cout << "Ready to be used!" << std::endl; }
  void CloseEverything() { std::cout << "Bup bup bup buzzzz!" << std::endl; }
  void Sooth() { std::cout << "Zzzzz" << std::endl; }
  void PullCurrent() { std::cout << "Haaah!" << std::endl; }
};

class ComputerFacade {
 public:
  explicit ComputerFacade(Computer& computer) : computer_(computer) {}
  void TurnOn() {
    computer_.GetElectricShock();
    computer_.MakeSound();
    computer_.ShowLoadingScreen();
    computer_.Bam();
  }
  void TurnOff() {
    computer_.CloseEverything();
    computer_.PullCurrent();
    computer_.Sooth();
  }

 private:
  Computer& computer_;
};
}  // namespace
TEST_CASE("[Facade]: ") {
  Computer real_computer;
  ComputerFacade computer(real_computer);
  computer.TurnOn();
  computer.TurnOff();
}
