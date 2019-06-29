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

#include <catch2/catch.hpp>  // for operator""_catch_sr, AssertionHandler, SourceLineInfo, StringRef, REQUIRE, TEST_CASE, REQUIRE_THROWS_AS, REQUIRE_FALSE
#include <folly/SocketAddress.h>  // for SocketAddress
#include <netinet/in.h>           // for htonl, htons, sockaddr_in, in_addr
#include <sys/socket.h>           // for AF_INET, AF_INET6, AF_UNIX, sockaddr_storage

#include <stdexcept>  // for invalid_argument
#include <string>     // for operator==, basic_string, string

TEST_CASE("[SocketAddress]: basic usage") {
  folly::SocketAddress addr("1.2.3.4", 4321);
  REQUIRE(addr.getFamily() == AF_INET);
  REQUIRE(addr.getAddressStr() == "1.2.3.4");
  REQUIRE(addr.getPort() == 4321);

  sockaddr_storage addrStorage;
  addr.getAddress(&addrStorage);
  const sockaddr_in* inaddr = reinterpret_cast<sockaddr_in*>(&addrStorage);
  REQUIRE(inaddr->sin_addr.s_addr == htonl(0x01020304));
  REQUIRE(inaddr->sin_port == htons(4321));
}

TEST_CASE("[SocketAddress]: setFromIpPort") {
  folly::SocketAddress addr;
  addr.setFromIpPort("[::]:1234");
  REQUIRE(addr.getFamily() == AF_INET6);
  REQUIRE(addr.getAddressStr() == "::");
  REQUIRE(addr.getPort() == 1234);
}

TEST_CASE("[SocketAddress]: is private") {
  folly::SocketAddress addr("9.255.255.255", 0);
  REQUIRE_FALSE(addr.isPrivateAddress());
  addr.setFromIpPort("11.0.0.0", 0);
  REQUIRE_FALSE(addr.isPrivateAddress());

  addr.setFromIpPort("10.0.0.0", 0);
  REQUIRE(addr.isPrivateAddress());
  addr.setFromIpPort("10.255.255.255", 0);
  REQUIRE(addr.isPrivateAddress());
}

TEST_CASE("[SocketAddress]: unix socket") {
  auto addr = folly::SocketAddress::makeFromPath("/tmp/unix.sock");
  REQUIRE(addr.getFamily() == AF_UNIX);
}

TEST_CASE("[SocketAddress]: describe") {
  REQUIRE(folly::SocketAddress("9.255.255.255", 0).describe() == "9.255.255.255:0");
  REQUIRE(folly::SocketAddress("::1", 0).describe() == "[::1]:0");

  // unix domian socket
  REQUIRE(folly::SocketAddress::makeFromPath("/tmp/unix.sock").describe() == "/tmp/unix.sock");
  REQUIRE(folly::SocketAddress::makeFromPath("\0tmp/unix.sock").describe() ==
          "<anonymous unix address>");
  std::string path(1, 0);
  path.append("tmp/unix.sock");
  REQUIRE(folly::SocketAddress::makeFromPath(path).describe() == "<abstract unix address>");
  path = "/tmp/unix.sock";
  path[0] = 0;
  REQUIRE(folly::SocketAddress::makeFromPath(path).describe() == "<abstract unix address>");
}

TEST_CASE("[SocketAddress]: get host/ip") {
  {
    folly::SocketAddress addr("9.255.255.255", 1100);
    REQUIRE(addr.getHostStr() == "9.255.255.255");
    REQUIRE(addr.getPort() == 1100);
    REQUIRE_THROWS_AS(addr.getPath(), std::invalid_argument);
    // REQUIRE(addr.getPath() == "");
  }
  {
    folly::SocketAddress addr("::1", 1100);
    // TODO: it's "localhost" on ubuntu
    // REQUIRE(addr.getHostStr() == "::1");
    REQUIRE(addr.getPort() == 1100);
  }
  {
    folly::SocketAddress addr("::", 1100);
    REQUIRE(addr.getHostStr() == "::");
    REQUIRE(addr.getPort() == 1100);
  }
  {
    auto addr = folly::SocketAddress::makeFromPath("/tmp/unix.sock");
    REQUIRE_THROWS_AS(addr.getHostStr(), std::invalid_argument);
    REQUIRE_THROWS_AS(addr.getPort(), std::invalid_argument);
    // REQUIRE(addr.getHostStr() == "");
    // REQUIRE(addr.getPort() == 0);
    REQUIRE(addr.getPath() == "/tmp/unix.sock");
  }
}

TEST_CASE("[SocketAddress]: not init addr") {
  folly::SocketAddress addr;
  REQUIRE(addr.describe() == "<uninitialized address>");
  REQUIRE(addr.getFamily() == AF_UNSPEC);
  REQUIRE_THROWS_AS(addr.getHostStr(), std::invalid_argument);
  REQUIRE_THROWS_AS(addr.getPort(), std::invalid_argument);
  REQUIRE_THROWS_AS(addr.getPath(), std::invalid_argument);
}

TEST_CASE("[SocketAddress]: reset") {
  folly::SocketAddress addr;
  addr.setFromIpPort("10.10.10.10", 1234);
  REQUIRE(addr.empty() == false);
  addr.reset();
  REQUIRE(addr.empty() == true);
}
