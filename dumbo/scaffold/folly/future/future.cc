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

#include <bits/exception.h>  // for exception
#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, operator""_catch_sr, AssertionHandler, TEST_CASE, REQUIRE, REQUIRE_THROWS_AS
#include <folly/Unit.h>      // for Unit
#include <folly/futures/Future.h>   // for Future, FutureInvalid (ptr only)
#include <folly/futures/Promise.h>  // for BrokenPromise

#include <type_traits>  // for decay<>::type, remove_reference<>::type
#include <utility>      // for move

TEST_CASE("[Future]: make empty ") {
  auto f = folly::Future<int>::makeEmpty();
  REQUIRE_THROWS_AS(f.isReady(), folly::FutureInvalid);
}

TEST_CASE("[Future]: future to unit") {
  folly::Future<folly::Unit> fu = folly::makeFuture().unit();
  fu.value();
  //   EXPECT_TRUE(makeFuture<Unit>(eggs).unit().hasException());
}

TEST_CASE("[Future]: then return") {
  folly::Future<int> ret = folly::makeFuture<int>(1).thenValue([](int&&) {
    return 2;
    //  return folly::Future<int>(2);
  });
  REQUIRE(std::move(ret).get() == 2);
}
