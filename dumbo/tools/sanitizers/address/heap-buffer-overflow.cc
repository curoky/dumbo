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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleHeapOutOfBounds
// RUN: clang -O -g -fsanitize=address %t && ./a.out

int main(int argc, char **argv) {
  int *array = new int[100];
  array[0] = 0;
  int res = array[argc + 100];  // BOOM
  delete[] array;
  return res;
}

// OUTPUT:
// clang-format off
/*
  $ bazel-bin/dumbo/bug/sanitizers/address/heap-buffer-overflow
  =================================================================
  ==540655==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6140000001d4 at pc 0x55db8f51b97b bp 0x7ffd93c02950 sp 0x7ffd93c02940
  READ of size 4 at 0x6140000001d4 thread T0
      #0 0x55db8f51b97a in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/heap-buffer-overflow+0x97a)
      #1 0x7faed36c40b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
      #2 0x55db8f51b80d in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/heap-buffer-overflow+0x80d)

  0x6140000001d4 is located 4 bytes to the right of 400-byte region [0x614000000040,0x6140000001d0)
  allocated by thread T0 here:
      #0 0x7faed3cceb47 in operator new[](unsigned long) (/lib/x86_64-linux-gnu/libasan.so.5+0x10fb47)
      #1 0x55db8f51b8e5 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/heap-buffer-overflow+0x8e5)
      #2 0x7faed36c40b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

  SUMMARY: AddressSanitizer: heap-buffer-overflow (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/heap-buffer-overflow+0x97a) in main
  Shadow bytes around the buggy address:
    0x0c287fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff8000: fa fa fa fa fa fa fa fa 00 00 00 00 00 00 00 00
    0x0c287fff8010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff8020: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  =>0x0c287fff8030: 00 00 00 00 00 00 00 00 00 00[fa]fa fa fa fa fa
    0x0c287fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x0c287fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x0c287fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x0c287fff8070: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x0c287fff8080: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  Shadow byte legend (one shadow byte represents 8 application bytes):
    Addressable:           00
    Partially addressable: 01 02 03 04 05 06 07
    Heap left redzone:       fa
    Freed heap region:       fd
    Stack left redzone:      f1
    Stack mid redzone:       f2
    Stack right redzone:     f3
    Stack after return:      f5
    Stack use after scope:   f8
    Global redzone:          f9
    Global init order:       f6
    Poisoned by user:        f7
    Container overflow:      fc
    Array cookie:            ac
    Intra object redzone:    bb
    ASan internal:           fe
    Left alloca redzone:     ca
    Right alloca redzone:    cb
    Shadow gap:              cc
  ==540655==ABORTING
*/
// clang-format on
