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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterScope
// RUN: clang -O -g -fsanitize=address -fsanitize-address-use-after-scope \
//    use-after-scope.cpp -o /tmp/use-after-scope
// RUN: /tmp/use-after-scope

// Check can be disabled in run-time:
// RUN: ASAN_OPTIONS=detect_stack_use_after_scope=0 /tmp/use-after-scope

volatile int *p = 0;

int main() {
  {
    int x = 0;
    p = &x;
  }
  *p = 5;
  return 0;
}

// OUTPUT:
// clang-format off
// =================================================================
// ==2549588==ERROR: AddressSanitizer: stack-use-after-scope on address 0x7fbec2bca020 at pc 0x560f64883b0b bp 0x7ffe9b826740 sp 0x7ffe9b826730
// WRITE of size 4 at 0x7fbec2bca020 thread T0
//     #0 0x560f64883b0a in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-scope+0xb0a)
//     #1 0x7fbec62b20b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
//     #2 0x560f6488393d in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-scope+0x93d)

// Address 0x7fbec2bca020 is located in stack of thread T0 at offset 32 in frame
//     #0 0x560f64883a08 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-scope+0xa08)

//   This frame has 1 object(s):
//     [32, 36) 'x' (line 13) <== Memory access at offset 32 is inside this variable
// HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
//       (longjmp and C++ exceptions *are* supported)
// SUMMARY: AddressSanitizer: stack-use-after-scope (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-scope+0xb0a) in main
// Shadow bytes around the buggy address:
//   0x0ff8585713b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff8585713c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff8585713d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff8585713e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff8585713f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x0ff858571400: f1 f1 f1 f1[f8]f3 f3 f3 00 00 00 00 00 00 00 00
//   0x0ff858571410: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff858571420: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff858571430: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff858571440: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ff858571450: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// Shadow byte legend (one shadow byte represents 8 application bytes):
//   Addressable:           00
//   Partially addressable: 01 02 03 04 05 06 07
//   Heap left redzone:       fa
//   Freed heap region:       fd
//   Stack left redzone:      f1
//   Stack mid redzone:       f2
//   Stack right redzone:     f3
//   Stack after return:      f5
//   Stack use after scope:   f8
//   Global redzone:          f9
//   Global init order:       f6
//   Poisoned by user:        f7
//   Container overflow:      fc
//   Array cookie:            ac
//   Intra object redzone:    bb
//   ASan internal:           fe
//   Left alloca redzone:     ca
//   Right alloca redzone:    cb
//   Shadow gap:              cc
// ==2549588==ABORTING
// clang-format on
