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

#pragma once
#include <bits/types/time_t.h>
#include <ctype.h>

extern "C" {
extern time_t mytime(time_t *__timer) __THROW;
time_t *time(time_t *__timer) __THROW __attribute__((alias("mytime")));

extern int myrand(void) __THROW;
int rand(void) __THROW __attribute__((alias("myrand")));

extern int myrand_r(unsigned int *__seed) __THROW;
int rand_r(unsigned int *__seed) __THROW __attribute__((alias("myrand_r")));
}
