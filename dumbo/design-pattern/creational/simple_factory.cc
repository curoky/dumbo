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
class Door {
 public:
  virtual double get_width() = 0;
  virtual double get_height() = 0;
  virtual ~Door() = default;
};

class WoodenDoor : public Door {
 public:
  WoodenDoor(double width, double height) : width_(width), height_(height) {}
  double get_width() override { return width_; }
  double get_height() override { return height_; }

 protected:
  double width_;
  double height_;
};

class DoorFactory {
 public:
  static Door* MakeDoor(double width, double heigh) { return new WoodenDoor(width, heigh); }
};
}  // namespace

TEST_CASE("[SimpleFactory]: ") {
  Door* door = DoorFactory::MakeDoor(100, 200);
  std::cout << "Width: " << door->get_width() << std::endl;
  std::cout << "Height: " << door->get_height() << std::endl;

  delete door;
}
