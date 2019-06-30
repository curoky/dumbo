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

#include <atomic>

namespace {
struct LockFreeType {
  int x, y;
};
struct NolockFreeType {
  int x, y, z;
};
}  // namespace

TEST_CASE("[Atomic]: lock free") {
  REQUIRE(std::atomic<bool>{}.is_lock_free());
  REQUIRE(std::atomic<int>{}.is_lock_free());
  REQUIRE(std::atomic<double>{}.is_lock_free());
  REQUIRE(std::atomic<long long>{}.is_lock_free());  // NOLINT
  REQUIRE(std::atomic<LockFreeType>{}.is_lock_free());
  REQUIRE_FALSE(std::atomic<NolockFreeType>{}.is_lock_free());
}
