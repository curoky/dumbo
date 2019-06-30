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
#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, operator""_catch_sr, AssertionHandler, TEST_CASE, Section, REQUIRE, SECTION
#include <folly/SocketAddress.h>               // for SocketAddress
#include <folly/io/async/AsyncServerSocket.h>  // for AsyncServerSocket
#include <folly/io/async/EventBase.h>          // for EventBase
#include <stdint.h>                            // for uint16_t
#include <unistd.h>                            // for unlink

#include <memory>  // for __shared_ptr_access, shared_ptr, allocator, allocator_traits<>::value_type
#include <string>  // for string
#include <utility>  // for addressof
#include <vector>   // for vector

TEST_CASE("[AsyncServerSocket]: basic usage") {
  folly::EventBase base;
  auto socket = folly::AsyncServerSocket::newSocket(&base);
  socket->bind(0);
  socket->listen(0);
  socket->startAccepting();
}

TEST_CASE("[AsyncServerSocket]: duplicate bind") {
  folly::EventBase base;
  auto server1 = folly::AsyncServerSocket::newSocket(&base);
  server1->bind(0);
  server1->listen(10);

  folly::SocketAddress address;
  server1->getAddress(std::addressof(address));

  auto server2 = folly::AsyncServerSocket::newSocket(&base);
  REQUIRE_THROWS_AS(server2->bind(address.getPort()), std::exception);
}

TEST_CASE("[AsyncServerSocket]: reuse port") {
  folly::EventBase base;
  auto socket = folly::AsyncServerSocket::newSocket(&base);
  socket->bind(0);
  socket->listen(0);
  socket->startAccepting();
  folly::SocketAddress address;
  socket->getAddress(&address);

  try {
    socket->setReusePortEnabled(true);
  } catch (...) {
    FAIL("Reuse port probably not supported");
  }

  auto socket2 = folly::AsyncServerSocket::newSocket(&base);
  socket2->setReusePortEnabled(true);
  socket2->bind(address.getPort());
  socket2->listen(0);
  socket2->startAccepting();
}

TEST_CASE("[AsyncServerSocket]: v4 v6 same port") {
  folly::EventBase base;
  auto serverSocket = folly::AsyncServerSocket::newSocket(&base);
  serverSocket->bind(0);
  auto addrs = serverSocket->getAddresses();
  REQUIRE(addrs.size() >= 0);

  // addrs := { [::]:19131, 0.0.0.0:19131 }
  uint16_t port = addrs[0].getPort();
  for (const auto& addr : addrs) {
    REQUIRE(port == addr.getPort());
  }
}

TEST_CASE("[AsyncServerSocket]: unix domain socket") {
  std::string path;
  SECTION("basic") { path = "/tmp/folly-domian-socket.sock"; }
  SECTION("abstract") {
    path = "/tmp/folly-domian-socket.sock";
    path[0] = 0;
  }
  unlink(path.c_str());

  auto addr = folly::SocketAddress::makeFromPath(path);
  folly::EventBase base;
  auto serverSocket = folly::AsyncServerSocket::newSocket(&base);
  serverSocket->setReusePortEnabled(true);
  serverSocket->bind(addr);

  auto serverSocket2 = folly::AsyncServerSocket::newSocket(&base);
  serverSocket2->setReusePortEnabled(true);
  // serverSocket2->bind(addr);
}
