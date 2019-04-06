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
 * @file: process_overflow.cc
 * ----------------------------------------------------------------------------
 */

#include <gflags/gflags.h>

#include <iostream>

DEFINE_int32(pre_stack_size, 1, "preallocate stack size(MB)");

const int MB = 1024 * 1024;

void test() {
  [[maybe_unused]] char buf[1 * MB];
  static int count = 0;
  std::cout << "count: " << count++ << std::endl;
  test();
}

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  [[maybe_unused]] char buf[FLAGS_pre_stack_size * MB];
  test();
  return 0;
}
