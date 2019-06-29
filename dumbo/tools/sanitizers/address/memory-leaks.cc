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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer
// RUN: clang -fsanitize=address -g memory-leak.c

#include <stdlib.h>

void *p;

int main() {
  p = malloc(7);
  p = 0;  // The memory is leaked here.
  return 0;
}

// OUTPUT:
// clang-format off
// =================================================================
// ==2553900==ERROR: LeakSanitizer: detected memory leaks

// Direct leak of 7 byte(s) in 1 object(s) allocated from:
//     #0 0x7fe0d78b0bc8 in malloc (/lib/x86_64-linux-gnu/libasan.so.5+0x10dbc8)
//     #1 0x5625584fe93a in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/memory-leaks+0x93a)
//     #2 0x7fe0d72a80b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

// SUMMARY: AddressSanitizer: 7 byte(s) leaked in 1 allocation(s).
// clang-format on
