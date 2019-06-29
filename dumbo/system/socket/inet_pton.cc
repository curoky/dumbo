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

#include <arpa/inet.h>       // for inet_pton
#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, StringRef, SourceLineInfo, REQUIRE, CAPTURE, Capturer, TEST_CASE
#include <netinet/in.h>      // for in6_addr, in_addr
#include <sys/socket.h>      // for AF_INET, AF_INET6

#include <cstdint>  // for uint64_t, int32_t

TEST_CASE("[InetPton]: basic usage") {
  REQUIRE(sizeof(struct in_addr) == 4);
  REQUIRE(sizeof(struct in6_addr) == 16);
  {
    int32_t addr;
    int ret = inet_pton(AF_INET, "10.11.22.33", &addr);
    REQUIRE(ret == 1);
    REQUIRE(addr == 555092746);
  }
  {
    int32_t addr;
    int ret = inet_pton(AF_INET, "2000:0000:0000:0000:0001:2345:6789:abcd", &addr);
    REQUIRE(ret == 0);
    // REQUIRE(addr == 0);
  }
  {
    // __int128_t addr;
    uint64_t addr[2];
    int ret = inet_pton(AF_INET6, "10.11.22.33", addr);
    REQUIRE(ret == 0);
    // REQUIRE(addr == 11);
  }
  {
    // __int128_t addr;
    uint64_t addr[2];
    int ret = inet_pton(AF_INET6, "2000:0000:0000:0001:0001:2345:6789:abcd", addr);
    REQUIRE(ret == 1);
    CAPTURE(addr);
    REQUIRE(addr[0] == 72057594037927968ULL);
    REQUIRE(addr[1] == 14820090075427307776ULL);
  }
}
