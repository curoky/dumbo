// REF: https://github.com/google/sanitizers/wiki/AddressSanitizerExampleGlobalOutOfBounds
// RUN: clang -O -g -fsanitize=address %t && ./a.out

int global_array[100] = {-1};
int main(int argc, char **argv) {
  return global_array[argc + 100];  // BOOM
}

// OUTPUT:
// clang-format off
// =================================================================
// ==2533238==ERROR: AddressSanitizer: global-buffer-overflow on address 0x55b5fa6db1b4 at pc 0x55b5fa6d999b bp 0x7ffda728f550 sp 0x7ffda728f540
// READ of size 4 at 0x55b5fa6db1b4 thread T0
//     #0 0x55b5fa6d999a in main (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/global-buffer-overflow+0x99a)
//     #1 0x7f47125b80b2 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
//     #2 0x55b5fa6d987d in _start (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/global-buffer-overflow+0x87d)

// 0x55b5fa6db1b4 is located 4 bytes to the right of global variable 'global_array' defined in 'dumbo/tools/sanitizers/address/global-buffer-overflow.cc:2:5' (0x55b5fa6db020) of size 400
// SUMMARY: AddressSanitizer: global-buffer-overflow (/home/curoky/.cache/bazel/_bazel_curoky/f0e58dbe6103f5cef1c1f24a78b6f904/execroot/com_github_curoky_dumbo/bazel-out/k8-fastbuild/bin/dumbo/tools/sanitizers/address/global-buffer-overflow+0x99a) in main
// Shadow bytes around the buggy address:
//   0x0ab73f4d35e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d35f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3600: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3610: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3620: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
// =>0x0ab73f4d3630: 00 00 00 00 00 00[f9]f9 f9 f9 f9 f9 00 00 00 00
//   0x0ab73f4d3640: f9 f9 f9 f9 f9 f9 f9 f9 00 00 00 00 00 00 00 00
//   0x0ab73f4d3650: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3660: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3670: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
//   0x0ab73f4d3680: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
// ==2533238==ABORTING
// clang-format on
