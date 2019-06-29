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

#include <catch2/catch.hpp>  // for Section, SourceLineInfo, SectionInfo, AssertionHandler, StringRef, WHEN, operator""_catch_sr, GIVEN, REQUIRE, SCENARIO
#include <folly/Format.h>    // for sformat
#include <glog/logging.h>    // for ErrnoLogMessage, PLOG
#include <string.h>          // for strncpy, memset
#include <sys/socket.h>      // for bind, socket, AF_UNIX, SOCK_STREAM
#include <sys/un.h>          // for sockaddr_un
#include <unistd.h>          // for close, unlink

#include <ostream>  // for operator<<
#include <string>   // for string, allocator

int bindUnixSocket(std::string socket_path) {
  int fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (fd == -1) {
    PLOG(ERROR) << "socket error";
    return -1;
  }

  sockaddr_un addr;
  // really need memset?
  memset(&addr, 0, sizeof(addr));
  addr.sun_family = AF_UNIX;

  if (*socket_path.c_str() == '\0') {
    // Abstract sockets
    // http://man7.org/linux/man-pages/man7/unix.7.html#h5o-3
    *addr.sun_path = '\0';
    strncpy(addr.sun_path + 1, socket_path.c_str() + 1, sizeof(addr.sun_path) - 2);
  } else {
    strncpy(addr.sun_path, socket_path.c_str(), sizeof(addr.sun_path) - 1);
    // we need delete socket file before bind
    // https://stackoverflow.com/questions/34873151/how-can-i-delete-a-unix-domain-socket-file-when-i-exit-my-application
    unlink(socket_path.c_str());
  }

  if (bind(fd, reinterpret_cast<sockaddr*>(&addr), sizeof(addr)) == -1) {
    PLOG(ERROR) << "bind error";
    return -2;
  }
  return fd;
}

SCENARIO("[UnixDomainSocket]: basic usage") {
  GIVEN("a socket path") {
    std::string socket_path = "/tmp/taro-test";
    WHEN("it isn't a abstract socket") {
      socket_path = folly::sformat("{}-domain2.sock", socket_path);
    }
    WHEN("it's a abstract socket") {
      socket_path = folly::sformat("\0{}-abstract-domain.sock", socket_path);
    }
    int fd = bindUnixSocket(socket_path);
    REQUIRE(fd > 0);
    close(fd);
  }
}
