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
 * ----------------------------------------------------------------------------
 * @file: any.cc
 * ----------------------------------------------------------------------------
 */

#include <catch2/catch.hpp>               // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, Section, SECTION, SectionInfo
#include <memory>                         // for allocator
#include <type_traits>                    // for remove_reference<>::type
#include <utility>                        // for move

#include "dumbo/utilities/class_utils.h"  // for ClassMetrics, ClassMetrics::Counter

#define USE_STD

#ifdef USE_STD
#include <any>                            // for any_cast, any, bad_any_cast

namespace detail {
using std::any;
using std::any_cast;
using std::bad_any_cast;
}  // namespace detail
#endif

#ifdef USE_BOOST
#include <boost/any.hpp>

namespace detail {
using boost::any;
using boost::any_cast;
using boost::bad_any_cast;
}  // namespace detail
#endif

#ifdef USE_ABSL
#include <absl/types/any.h>
#include <absl/types/bad_any_cast.h>

namespace detail {
using absl::any;
using absl::any_cast;
using absl::bad_any_cast;
using absl::make_any;
}  // namespace detail
#endif

using taro::util::ClassMetrics;

TEST_CASE("[Any]: construct") {
  ClassMetrics::Counter counter;

  ClassMetrics cm(counter);

  counter.reset();

  SECTION("lvalue") {
    detail::any _ = cm;
    REQUIRE(counter.copy_cons == 1);
    REQUIRE(counter.move_cons == 0);
  }
  SECTION("rvalue") {
    detail::any _ = ClassMetrics(counter);
    REQUIRE(counter.copy_cons == 0);
    REQUIRE(counter.move_cons == 1);
  }
  SECTION("move lvalue") {
    detail::any _ = std::move(cm);
    REQUIRE(counter.copy_cons == 0);
    REQUIRE(counter.move_cons == 1);
  }
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
TEST_CASE("[Any]: cast get") {
  ClassMetrics::Counter counter;

  detail::any cm = ClassMetrics(counter);

  counter.reset();

  // Construct::reset();
  // detail::any cat = Construct();
  // Construct::reset();
  SECTION("no ref") {
    ClassMetrics _ = detail::any_cast<ClassMetrics>(cm);
    REQUIRE(counter.copy_cons == 1);
    REQUIRE(counter.move_cons == 0);
  }
  SECTION("lvalue ref") {
    ClassMetrics& _ = detail::any_cast<ClassMetrics&>(cm);
    REQUIRE(counter.copy_cons == 0);
    REQUIRE(counter.move_cons == 0);
  }
  SECTION("rvalue ref") {
    ClassMetrics _ = detail::any_cast<ClassMetrics&&>(std::move(cm));
    REQUIRE(counter.copy_cons == 0);
    REQUIRE(counter.move_cons == 1);
  }

  SECTION("point") {
    ClassMetrics* _ = detail::any_cast<ClassMetrics>(&cm);
    REQUIRE(counter.copy_cons == 0);
    REQUIRE(counter.move_cons == 0);
  }
}
#pragma GCC diagnostic pop

TEST_CASE("[Any]: BadAnyCastTest") {
  detail::any int_value = 1;
  REQUIRE_THROWS_AS(detail::any_cast<float>(int_value), detail::bad_any_cast);
}
