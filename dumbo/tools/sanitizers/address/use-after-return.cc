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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterReturn
// RUN: clang -O -g -fsanitize=address %t && ./a.out
// By default, AddressSanitizer does not try to detect
// stack-use-after-return bugs.
// It may still find such bugs occasionally
// and report them as a hard-to-explain stack-buffer-overflow.

// You need to run the test with ASAN_OPTIONS=detect_stack_use_after_return=1

int *ptr;
__attribute__((noinline)) void FunctionThatEscapesLocalObject() {
  int local[100];
  ptr = &local[0];
}

int main(int argc, char **argv) {
  FunctionThatEscapesLocalObject();
  return ptr[argc];
}

// OUTPUT:
// clang-format off
// =================================================================
// ==2546263==ERROR: AddressSanitizer: stack-use-after-return on address 0x7f109de85034 at pc 0x55eb59ec6b88 bp 0x7ffd88ad1990 sp 0x7ffd88ad1980
// READ of size 4 at 0x7f109de85034 thread T0
//     #0 0x55eb59ec6b87 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-return+0xb87)
//     #1 0x7f10a126d0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
//     #2 0x55eb59ec693d in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-return+0x93d)

// Address 0x7f109de85034 is located in stack of thread T0 at offset 52 in frame
//     #0 0x55eb59ec6a08 in FunctionThatEscapesLocalObject() (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-return+0xa08)

//   This frame has 1 object(s):
//     [48, 448) 'local' (line 13) <== Memory access at offset 52 is inside this variable
// HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
//       (longjmp and C++ exceptions *are* supported)
// SUMMARY: AddressSanitizer: stack-use-after-return (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/use-after-return+0xb87) in main
// Shadow bytes around the buggy address:
//   0x0fe293bc89b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0fe293bc89c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0fe293bc89d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0fe293bc89e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0fe293bc89f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x0fe293bc8a00: f5 f5 f5 f5 f5 f5[f5]f5 f5 f5 f5 f5 f5 f5 f5 f5
//   0x0fe293bc8a10: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
//   0x0fe293bc8a20: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
//   0x0fe293bc8a30: f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5 f5
//   0x0fe293bc8a40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0fe293bc8a50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
// ==2546263==ABORTING
// clang-format on
