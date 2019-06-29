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

#include "lib.h"

Constructor c2("global c2");
Constructor c1("global c1");
Constructor c30("global local c30");
Constructor c3("global c3");

Constructor __attribute__((init_priority(110))) c20("global init_priority 110");
Constructor __attribute__((init_priority(101))) c21("global init_priority 101");

Constructor& get_inner_static() {
  static Constructor c("inner_func_static");
  return c;
}

void global_init_101() {
  (void)get_inner_static();
  printf("global constructor 101\n");
}

void global_init_102() { printf("global constructor 102\n"); }
