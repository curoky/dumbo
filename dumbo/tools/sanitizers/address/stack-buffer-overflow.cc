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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleStackOutOfBounds
// RUN: clang -O -g -fsanitize=address %t && ./a.out

int main(int argc, char **argv) {
  int stack_array[100];
  stack_array[1] = 0;
  return stack_array[argc + 100];  // BOOM
}

// OUTPUT:
// clang-format off
// =================================================================
// ==2540450==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fff877255b4 at pc 0x562414ceba28 bp 0x7fff877253d0 sp 0x7fff877253c0
// READ of size 4 at 0x7fff877255b4 thread T0
//     #0 0x562414ceba27 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/stack-buffer-overflow+0xa27)
//     #1 0x7ff0459890b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
//     #2 0x562414ceb82d in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/stack-buffer-overflow+0x82d)

// Address 0x7fff877255b4 is located in stack of thread T0 at offset 452 in frame
//     #0 0x562414ceb8f8 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/stack-buffer-overflow+0x8f8)

//   This frame has 1 object(s):
//     [48, 448) 'stack_array' (line 5) <== Memory access at offset 452 overflows this variable
// HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
//       (longjmp and C++ exceptions *are* supported)
// SUMMARY: AddressSanitizer: stack-buffer-overflow (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/stack-buffer-overflow+0xa27) in main
// Shadow bytes around the buggy address:
//   0x100070edca60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edca70: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 f1 f1
//   0x100070edca80: f1 f1 f1 f1 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edca90: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edcaa0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x100070edcab0: 00 00 00 00 00 00[f3]f3 f3 f3 f3 f3 f3 f3 00 00
//   0x100070edcac0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edcad0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edcae0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edcaf0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x100070edcb00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
// ==2540450==ABORTING
// clang-format on
