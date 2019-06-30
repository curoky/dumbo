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

/*
 * 高效的并发hash_map
 * 限制:
 *  1. 被删除元素的内存无法释放
 *  2. 仅支持32位与64位的key(需要进行原子操作)
 *  3. 超出初始化时设置的大小后, 性能会降低
 *  4. value并发需要在外部同步
 *  5. 设置三个保留的key empty, erased, locked
 * 特性:
 *  1. value的引用始终有效, 内部不会发生value拷贝
 *  2. 内部冗余的32位id可以用来索引, 以减少内存开销(相比 64)
 *  3. 迭代器永不失效
 */

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <folly/AtomicHashMap.h>  // for AtomicHashMap<>::ahm_iterator, AtomicHashMap, AtomicHashMap<>::Config
#include <folly/detail/Futex-inl.h>  // for futexWake, futexWait
#include <folly/detail/Iterators.h>  // for IteratorFacade
#include <sys/types.h>               // for ushort

#include <cstdint>  // for int32_t
#include <map>      // for pair

TEST_CASE("[Atomichashmap]: simple test") {
  folly::AtomicHashMap<int32_t, ushort>::Config config;
  REQUIRE(config.emptyKey == -1);
  folly::AtomicHashMap<int32_t, ushort> mp(100000);
  mp.insert(1, 22);
  auto ret = mp.find(1);
  REQUIRE(ret != mp.end());
  REQUIRE(ret->second == 22);
}
