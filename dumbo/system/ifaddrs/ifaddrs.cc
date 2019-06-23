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
 * @file: ifaddrs.cc
 * ----------------------------------------------------------------------------
 */

// http://man7.org/linux/man-pages/man3/getifaddrs.3.html#EXAMPLE

#include <catch2/catch.hpp>  // for operator""_catch_sr, SourceLineInfo, StringRef, AssertionHandler, FAIL, TEST_CASE
#include <ifaddrs.h>        // for ifaddrs, freeifaddrs, getifaddrs
#include <linux/if_link.h>  // for rtnl_link_stats
#include <netdb.h>          // for gai_strerror, getnameinfo, NI_MAXHOST, NI_NUMERICHOST
#include <netinet/in.h>     // for sockaddr_in, sockaddr_in6
#include <stdio.h>          // for printf, NULL, perror
#include <sys/socket.h>     // for AF_INET, AF_INET6, AF_PACKET, sockaddr

TEST_CASE("[Ifaddrs]: simple test") {
  /*
  lo       AF_PACKET (17)
                  tx_packets =  361683198; rx_packets =  361683198
                  tx_bytes   = 3714118275; rx_bytes   = 3714118275
  eth0     AF_PACKET (17)
                  tx_packets = 2560646282; rx_packets = 3189477124
                  tx_bytes   =  730767045; rx_bytes   = 1641058594
  docker0  AF_PACKET (17)
                  tx_packets =         14; rx_packets =        135
                  tx_bytes   =        588; rx_bytes   =       8132
  lo       AF_INET (2)
                  address: <127.0.0.1>
  eth0     AF_INET (2)
                  address: <10.115.139.242>
  docker0  AF_INET (2)
                  address: <172.17.0.1>
  tun4     AF_INET (2)
                  address: <192.168.100.102>
  eth0     AF_INET6 (10)
                  address: <fe80::216:3eff:fe02:ccb6%eth0>
  */
  struct ifaddrs *ifaddr, *ifa;
  int family, s, n;
  char host[NI_MAXHOST];

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    FAIL("getifaddrs error");
    // exit(EXIT_FAILURE);
  }

  /* Walk through linked list, maintaining head pointer so we
     can free list later */

  for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
    if (ifa->ifa_addr == NULL) continue;

    family = ifa->ifa_addr->sa_family;

    /* Display interface name and family (including symbolic
       form of the latter for the common families) */

    printf("%-8s %s (%d)\n", ifa->ifa_name,
           (family == AF_PACKET)  ? "AF_PACKET"
           : (family == AF_INET)  ? "AF_INET"
           : (family == AF_INET6) ? "AF_INET6"
                                  : "???",
           family);

    /* For an AF_INET* interface address, display the address */

    if (family == AF_INET || family == AF_INET6) {
      s = getnameinfo(
          ifa->ifa_addr,
          (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6), host,
          NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      if (s != 0) {
        FAIL("getnameinfo() failed: " << gai_strerror(s));
        // exit(EXIT_FAILURE);
      }

      // printf("\t\taddress: <%s>\n", host);
      printf("\t\taddress: %s \n", host);

    } else if (family == AF_PACKET && ifa->ifa_data != NULL) {
      struct rtnl_link_stats* stats = static_cast<rtnl_link_stats*>(ifa->ifa_data);

      printf(
          "\t\ttx_packets = %10u; rx_packets = %10u\n"
          "\t\ttx_bytes   = %10u; rx_bytes   = %10u\n",
          stats->tx_packets, stats->rx_packets, stats->tx_bytes, stats->rx_bytes);
    }
  }

  freeifaddrs(ifaddr);
  // exit(EXIT_SUCCESS);
}
