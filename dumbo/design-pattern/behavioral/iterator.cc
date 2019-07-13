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

#include <iostream>  // for endl, basic_ostream<>::__ostream_type, cout, ostream
#include <vector>    // for vector<>::iterator, vector, find

namespace {
class RadioStation {
  friend bool operator==(const RadioStation& lhs, const RadioStation& rhs) {
    return lhs.frequency_ == rhs.frequency_;
  }

 public:
  explicit RadioStation(float frequency) : frequency_(frequency) {}
  float GetFrequency() const { return frequency_; }

 private:
  float frequency_;
};

class StationList {
  using Iter = std::vector<RadioStation>::iterator;

 public:
  void AddStation(const RadioStation& station) { stations_.push_back(station); }
  void RemoveStation(const RadioStation& toRemove) {
    auto found = std::find(stations_.begin(), stations_.end(), toRemove);
    if (found != stations_.end()) stations_.erase(found);
  }
  Iter begin() { return stations_.begin(); }
  Iter end() { return stations_.end(); }

 private:
  std::vector<RadioStation> stations_;
};
}  // namespace
TEST_CASE("[Iterator]: ") {
  StationList stationList;
  stationList.AddStation(RadioStation(89));
  stationList.AddStation(RadioStation(101));
  stationList.AddStation(RadioStation(102));
  stationList.AddStation(RadioStation(103.2));

  for (auto&& station : stationList) std::cout << station.GetFrequency() << std::endl;

  stationList.RemoveStation(RadioStation(89));  // Will remove station 89
}
