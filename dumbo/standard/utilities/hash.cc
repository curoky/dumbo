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

#include <boost/container_hash/extensions.hpp>  // for hash
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <iosfwd>         // for size_t
#include <string>         // for allocator, hash, string, u16string, u32string, wstring
#include <unordered_map>  // for hash, unordered_map, pair
#include <variant>        // for hash

TEST_CASE("[Hash]: basic types") {
  // basic types
  REQUIRE(std::hash<bool>()(true) == 1);
  REQUIRE(std::hash<char>()('1') == 49);
  REQUIRE(std::hash<int>()(1) == 1);
  REQUIRE(std::hash<long>()(1) == 1);           //  NOLINT
  REQUIRE(std::hash<long int>()(1) == 1);       //  NOLINT
  REQUIRE(std::hash<long long>()(1) == 1);      //  NOLINT
  REQUIRE(std::hash<long long int>()(1) == 1);  //  NOLINT

  REQUIRE(std::hash<unsigned long>()(1) == 1);           //  NOLINT
  REQUIRE(std::hash<unsigned long int>()(1) == 1);       //  NOLINT
  REQUIRE(std::hash<unsigned long long>()(1) == 1);      //  NOLINT
  REQUIRE(std::hash<unsigned long long int>()(1) == 1);  //  NOLINT

  // library types
  REQUIRE(std::hash<std::string>()("000") == 9952612648141622413UL);
  REQUIRE(std::hash<std::wstring>()(L"000") == 6249330993455828750UL);
  // REQUIRE(std::hash<std::u8string>()(u8"000") == 9952612648141622413UL); // c++2a
  REQUIRE(std::hash<std::u16string>()(u"000") == 16777420074585146182UL);
  REQUIRE(std::hash<std::u32string>()(U"000") == 6249330993455828750UL);
}

struct Person {
  std::string name;
  std::string sex;
};

namespace std {
template <>
struct hash<Person> {
  std::size_t operator()(Person const& p) const noexcept {
    std::size_t h1 = std::hash<std::string>{}(p.name);
    std::size_t h2 = std::hash<std::string>{}(p.sex);
    return h1 ^ (h2 << 1);  // or use boost::hash_combine
  }
};
}  // namespace std

TEST_CASE("[Hash]: custom hash") {
  std::size_t h = std::hash<Person>()(Person{"h", "g"});
  REQUIRE(h == 17008283680475833480UL);
}

TEST_CASE("[Hash]: hash map key") {
  using PairType = std::pair<std::string, bool>;

  struct PairTypeHash {
    std::size_t operator()(const PairType& pair) const {
      return std::hash<std::string>()(pair.first) ^ std::hash<bool>()(pair.second);
    }
  };

  std::unordered_map<PairType, int, PairTypeHash> mp1;
  std::unordered_map<PairType, int, boost::hash<PairType>> mp2;
}
