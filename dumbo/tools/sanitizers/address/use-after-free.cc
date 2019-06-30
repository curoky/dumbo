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

// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleUseAfterFree
// RUN: clang -O -g -fsanitize=address %t && ./a.out

int main(int argc, char **argv) {
  int *array = new int[100];
  delete[] array;
  return array[argc];  // BOOM
}

// another version
/*
#include <stdlib.h>
int main() {
  char *x = (char *)malloc(10 * sizeof(char *));
  free(x);
  return x[5];
}
*/

// OUTPUT:
// clang-format off
/*
  $ bazel-bin/dumbo/bug/sanitizers/address/use-after-free
  =================================================================
  ==539522==ERROR: AddressSanitizer: heap-use-after-free on address 0x614000000044 at pc 0x55c0dbdda8e9 bp 0x7ffea8242d10 sp 0x7ffea8242d00
  READ of size 4 at 0x614000000044 thread T0
      #0 0x55c0dbdda8e8 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/use-after-free+0x8e8)
      #1 0x7f116deec0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
      #2 0x55c0dbdda7ad in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/use-after-free+0x7ad)

  0x614000000044 is located 4 bytes inside of 400-byte region [0x614000000040,0x6140000001d0)
  freed by thread T0 here:
      #0 0x7f116e4f7aaf in operator delete[](void*) (/lib/x86_64-linux-gnu/libasan.so.5+0x110aaf)
      #1 0x55c0dbdda89c in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/use-after-free+0x89c)
      #2 0x7f116deec0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

  previously allocated by thread T0 here:
      #0 0x7f116e4f6b47 in operator new[](unsigned long) (/lib/x86_64-linux-gnu/libasan.so.5+0x10fb47)
      #1 0x55c0dbdda885 in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/use-after-free+0x885)
      #2 0x7f116deec0b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)

  SUMMARY: AddressSanitizer: heap-use-after-free (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/bug/sanitizers/address/use-after-free+0x8e8) in main
  Shadow bytes around the buggy address:
    0x0c287fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
    0x0c287fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  =>0x0c287fff8000: fa fa fa fa fa fa fa fa[fd]fd fd fd fd fd fd fd
    0x0c287fff8010: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
    0x0c287fff8020: fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd fd
    0x0c287fff8030: fd fd fd fd fd fd fd fd fd fd fa fa fa fa fa fa
    0x0c287fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
    0x0c287fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
  ==539522==ABORTING
*/
// clang-format on
