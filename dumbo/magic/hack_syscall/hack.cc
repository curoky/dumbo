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

#include "hack.h"

// #include <stdlib.h>
// #include <time.h>
// #include <bits/time.h>

// extern int __clock_gettime(clockid_t clock_id, struct timespec *ts);

time_t mytime(time_t *__timer) __THROW {
  // struct timespec ts;
  // __clock_gettime(CLOCK_REALTIME, &ts);

  // if (__timer) *__timer = ts.tv_sec;
  // return ts.tv_sec / 1000;
  return 10010;
}

int myrand(void) __THROW {
  //
  return 10086;
}

int myrand_r(unsigned int *__seed) __THROW {
  //
  return 10087;
}
