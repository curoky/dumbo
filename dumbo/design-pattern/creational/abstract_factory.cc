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
class Door {
 public:
  virtual void get_description() = 0;
  virtual ~Door() = default;
};

class WoodenDoor : public Door {
 public:
  void get_description() override { std::cout << "I am a wooden door" << std::endl; }
};

class IronDoor : public Door {
 public:
  void get_description() override { std::cout << "I am a iron door" << std::endl; }
};

class DoorFittingExpert {
 public:
  virtual void get_description() = 0;
  virtual ~DoorFittingExpert() = default;
};

class Welder : public DoorFittingExpert {
 public:
  void get_description() { std::cout << "I can only fit iron doors" << std::endl; }
};

class Carpenter : public DoorFittingExpert {
 public:
  void get_description() { std::cout << "I can only fit wooden doors" << std::endl; }
};

class DoorFactory {
 public:
  virtual Door* makeDoor() = 0;
  virtual DoorFittingExpert* makeFittingExpert() = 0;
  virtual ~DoorFactory() = default;
};

// Wooden factory to return carpenter and wooden door
class WoodenDoorFactory : public DoorFactory {
 public:
  Door* makeDoor() override { return new WoodenDoor(); }
  DoorFittingExpert* makeFittingExpert() override { return new Carpenter(); }
};

// Iron door factory to get iron door and the relevant fitting expert
class IronDoorFactory : public DoorFactory {
 public:
  Door* makeDoor() override { return new IronDoor(); }
  DoorFittingExpert* makeFittingExpert() override { return new Welder(); }
};
}  // namespace
TEST_CASE("[AbstractFactory]: ") {
  {
    auto woodenFactory = new WoodenDoorFactory();
    auto door = woodenFactory->makeDoor();
    auto expert = woodenFactory->makeFittingExpert();

    door->get_description();    // Output: I am a wooden door
    expert->get_description();  // Output: I can only fit wooden doors

    delete door;
    delete expert;
    delete woodenFactory;
  }

  {
    // Same for Iron Factory
    auto ironFactory = new IronDoorFactory();
    auto door = ironFactory->makeDoor();
    auto expert = ironFactory->makeFittingExpert();

    door->get_description();    // Output: I am an iron door
    expert->get_description();  // Output: I can only fit iron doors}

    delete door;
    delete expert;
    delete ironFactory;
  }
}
