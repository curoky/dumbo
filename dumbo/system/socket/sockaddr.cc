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

#include <catch2/catch.hpp>  // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <stddef.h>      // for offsetof
#include <sys/socket.h>  // for socklen_t
#include <sys/un.h>      // for sockaddr_un

#include <string>  // for string, allocator

TEST_CASE("[Sockaddr]: length") {
  sockaddr_un addr;
  socklen_t LEN_sockaddr_un = sizeof(sockaddr_un);
  socklen_t LEN_sun_path = sizeof(addr.sun_path);
  socklen_t OFF_sun_path = socklen_t(offsetof(struct sockaddr_un, sun_path));
  REQUIRE(LEN_sockaddr_un == 110);
  REQUIRE(LEN_sun_path == 108);
  REQUIRE(OFF_sun_path == 2);

  std::string path = "/tmp/domain_socket_test986072723.sock";
  path[0] = 0;
  REQUIRE(path.size() == 37);

  REQUIRE(LEN_sockaddr_un - (LEN_sun_path - path.size()) == 39);

  REQUIRE(OFF_sun_path + path.size() == 39);
}
