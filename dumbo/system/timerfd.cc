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

#include <catch2/catch.hpp>  // for SourceLineInfo, StringRef, TEST_CASE
#include <sys/time.h>        // for CLOCK_REALTIME
#include <sys/timerfd.h>     // for timerfd_create, TFD_NONBLOCK

TEST_CASE("[Timerfd]: simple test") {
  // TODO(curoky): implement it
  int tfd = timerfd_create(CLOCK_REALTIME, TFD_NONBLOCK);
  (void)tfd;
  // ASSERT_EQ(tfd, 0);
  // int ret = timerfd_settime(tfd, 0, )
}
