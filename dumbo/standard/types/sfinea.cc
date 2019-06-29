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

// reference:
// https://stackoverflow.com/questions/1005476/how-to-detect-whether-there-is-a-specific-member-variable-in-class
// https://www.hashcoding.net/2015/12/21/SFINAE%E3%80%81std-declval%E6%9D%82%E8%B0%88/

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE

#include <type_traits>  // for integral_constant<>::value, enable_if, false_type, true_type
#include <utility>      // for declval

namespace demo1 {

template <typename T, typename = void>
struct has_id : std::false_type {};

template <typename T>
struct has_id<T, decltype(std::declval<T>().id, void())> : std::true_type {};

template <typename T>
typename std::enable_if<has_id<T>::value, bool>::type judge_id(const T&) {
  return true;
}

template <typename T>
typename std::enable_if<!has_id<T>::value, bool>::type judge_id(const T&) {
  return false;
}
}  // namespace demo1

namespace demo2 {

struct if_default_ {};
struct if_has_id_ : public if_default_ {};

template <typename T, typename = decltype(T::id)>
bool has_id(const T&, if_has_id_) {
  return true;
}

template <typename T>
bool has_id(const T&, if_default_) {
  return false;
}

template <typename T>
bool judge_id(const T& req) {
  return has_id(req, if_has_id_{});
}
}  // namespace demo2

namespace demo3 {

template <typename T>
struct hasIdAsMember {
 private:
  template <typename C>
  static constexpr decltype(std::declval<C>().id, bool()) check(int) {
    return true;
  }
  template <typename C>
  static constexpr bool check(...) {
    return false;
  }

 public:
  static constexpr bool value = check<T>(int());
};

template <typename T>
typename std::enable_if<hasIdAsMember<T>::value, bool>::type judge_id(const T&) {
  return true;
}
template <typename T>
typename std::enable_if<!hasIdAsMember<T>::value, bool>::type judge_id(const T&) {
  return false;
}

}  // namespace demo3

TEST_CASE("[Sfinea]: HasMemberTest") {
  struct Type_t {
    int id = 100;
  };
  REQUIRE(demo1::has_id<Type_t>::value == true);
  REQUIRE(demo1::has_id<int>::value == false);
  REQUIRE(demo1::judge_id(Type_t()) == true);
  REQUIRE(demo1::judge_id(int()) == false);

  REQUIRE(demo2::judge_id(Type_t()) == true);
  REQUIRE(demo2::judge_id(int()) == false);

  REQUIRE(demo3::judge_id(Type_t()) == true);
  REQUIRE(demo3::judge_id(int()) == false);
}
