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

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <catch2/catch.hpp>

#include <iostream>
#include <map>
#include <string>

class gps_position {
 public:
  int degrees;
  int minutes;
  float seconds;
  gps_position(){};
  gps_position(int d, int m, float s) : degrees(d), minutes(m), seconds(s) {}
};

namespace boost {
namespace serialization {

template <class Archive>
void serialize(Archive& ar, gps_position& g, const unsigned int version) {
  ar& g.degrees;
  ar& g.minutes;
  ar& g.seconds;
}

}  // namespace serialization
}  // namespace boost

TEST_CASE("[Serialization]: basic usage") {
  gps_position g(1, 2, 3);

  std::stringstream ss;
  boost::archive::text_oarchive ia(ss);
  // boost::archive::xml_oarchive ia(ss);
  ia << g;

  REQUIRE(ss.str() == "22 serialization::archive 18 0 0 1 2 3.000000000e+00");
}

TEST_CASE("[Serialization]: STL case") {
  std::vector<std::string> string_vector{"1", "2", "3"};
  std::map<std::string, std::string> string_map = {{"1", "2"}, {"3", "4"}};

  {
    std::ostringstream oStringStream;
    boost::archive::binary_oarchive oa(oStringStream);
    oa << BOOST_SERIALIZATION_NVP(string_vector);

    // REQUIRE(oStringStream.str() == "22 serialization::archive 18 0 0 3 0 1 1 1 2 1 3");

    std::string strData = oStringStream.str();
    std::istringstream iStringStream(strData, std::istringstream::in);
    boost::archive::binary_iarchive ia(iStringStream);
    std::vector<std::string> string_vector_cp;
    ia >> BOOST_SERIALIZATION_NVP(string_vector_cp);

    REQUIRE(string_vector == string_vector_cp);
  }

  {
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << string_map;
    REQUIRE(ss.str() == "22 serialization::archive 18 0 0 2 0 0 0 1 1 1 2 1 3 1 4");
  }
}
