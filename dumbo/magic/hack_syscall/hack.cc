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

// Ref:
// https://rafalcieslak.wordpress.com/2013/04/02/dynamic-linker-tricks-using-ld_preload-to-cheat-inject-features-and-investigate-programs/

#include "hack.h"

#include <dlfcn.h>

typedef time_t (*orig_time_type)(time_t *__timer);

time_t mytime(time_t *__timer) __THROW {
  orig_time_type gtime = (orig_time_type)dlsym(RTLD_NEXT, "time");
  return gtime(nullptr);
}

int myrand(void) __THROW {
  //
  return 10086;
}

int myrand_r(unsigned int *__seed) __THROW {
  //
  return 10087;
}
