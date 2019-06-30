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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_...

#include <cstdint>
#include <limits>  // for numeric_limits

template <typename T>
T lowest() {
  return std::numeric_limits<T>::lowest();
}

template <typename T>
T min() {
  return std::numeric_limits<T>::min();
}

template <typename T>
T max() {
  return std::numeric_limits<T>::max();
}

TEST_CASE("[NumericLimits]: simple test") {
  // https://en.cppreference.com/w/cpp/types/numeric_limits

  // type    lowest()        min()           max()
  // uchar   0               0               255
  // int     -2147483648     -2147483648     2147483647
  // float   -3.40282e+38    1.17549e-38     3.40282e+38
  // double  -1.79769e+308   2.22507e-308    1.79769e+308

  REQUIRE(lowest<int>() == -2147483648);
  REQUIRE(min<int>() == -2147483648);
  REQUIRE(max<int>() == 2147483647);

  // 2^62 = 4611686018427387904
  REQUIRE(std::numeric_limits<int64_t>::max() == 9223372036854775807);
  REQUIRE(std::numeric_limits<uint64_t>::max() == 18446744073709551615ULL);
  REQUIRE(std::numeric_limits<int32_t>::max() == 2147483647);
  REQUIRE(std::numeric_limits<uint32_t>::max() == 4294967295);
  REQUIRE(std::numeric_limits<int16_t>::max() == 32767);
  REQUIRE(std::numeric_limits<uint16_t>::max() == 65535);
  // REQUIRE(std::numeric_limits<int8_t>::max() == 1LL);
  // REQUIRE(std::numeric_limits<uint8_t>::max() == 1LL);

  // std::cout << "type\tlowest()\tmin()\t\tmax()\n\n";
  // std::cout << "uchar\t" << +std::numeric_limits<unsigned char>::lowest() << '\t' << '\t'
  //           << +std::numeric_limits<unsigned char>::min() << '\t' << '\t'
  //           << +std::numeric_limits<unsigned char>::max() << '\n';
  // std::cout << "int\t" << std::numeric_limits<int>::lowest() << '\t'
  //           << std::numeric_limits<int>::min() << '\t' << std::numeric_limits<int>::max() <<
  //           '\n';
  // std::cout << "float\t" << std::numeric_limits<float>::lowest() << '\t'
  //           << std::numeric_limits<float>::min() << '\t' << std::numeric_limits<float>::max()
  //           << '\n';
  // std::cout << "double\t" << std::numeric_limits<double>::lowest() << '\t'
  //           << std::numeric_limits<double>::min() << '\t' << std::numeric_limits<double>::max()
  //           << '\n';
}
