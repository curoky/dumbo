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
#include <string>    // for string, operator+, operator<<, allocator

namespace {
class Theme {
 public:
  virtual std::string getColor() = 0;
};

class DarkTheme : public Theme {
 public:
  std::string getColor() override { return "Dark Black"; }
};
class LightTheme : public Theme {
 public:
  std::string getColor() override { return "Off white"; }
};
class AquaTheme : public Theme {
 public:
  std::string getColor() override { return "Light blue"; }
};

class WebPage {
 public:
  explicit WebPage(Theme& theme) : theme_(theme) {}
  virtual std::string getContent() = 0;

 protected:
  Theme& theme_;
};

class About : public WebPage {
 public:
  explicit About(Theme& theme) : WebPage(theme) {}

  std::string getContent() override { return "About page in " + theme_.getColor(); }
};

class Careers : public WebPage {
 public:
  explicit Careers(Theme& theme) : WebPage(theme) {}

  std::string getContent() override { return "Careers page in " + theme_.getColor(); }
};
}  // namespace
TEST_CASE("[Bridge]: ") {
  DarkTheme darkTheme;
  About about(darkTheme);
  Careers careers(darkTheme);

  std::cout << about.getContent() << std::endl;
  std::cout << careers.getContent() << std::endl;
}
