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

#include <benchmark/benchmark.h>
#include <string.h>

#include <algorithm>

/**
 * @brief memset implement v1, basic basic basic.
 *
 * @param b begin point
 * @param e end point
 * @param c char data
 */
inline void memset_simp(char* b, char* e, char c) {
  for (; b != e; ++b) {
    *b = c;
  }
}

/**
 * @brief memset implement v2, loop unrolling
 *
 * @param b
 * @param e
 * @param c
 */
inline void memset_unroll(char* b, char* e, char c) {
  auto const ee = b + ((e - b) & ~7u);
  for (; b != ee; b += 8) {
    b[0] = c;
    b[1] = c;
    b[2] = c;
    b[3] = c;
    b[4] = c;
    b[5] = c;
    b[6] = c;
    b[7] = c;
  }
  // Leftovers
  for (; b != e; ++b) {
    *b = c;
  }
}

/**
 * @brief glibc impl for memset,
 * https://sourceware.org/git/?p=glibc.git;a=blob_plain;f=string/memset.c;hb=HEAD
 *
 * @param dstpp
 * @param c
 * @param len
 * @return void*
 */
#define op_t unsigned long int  // NOLINT
#define OPSIZ (sizeof(op_t))
typedef unsigned char byte;

void* glibc_memset(char* dstpp, int c, size_t len) {
  long int dstp = (long int)dstpp;  // NOLINT

  if (len >= 8) {
    size_t xlen;
    op_t cccc;

    cccc = (unsigned char)c;
    cccc |= cccc << 8;
    cccc |= cccc << 16;
    if (OPSIZ > 4) /* Do the shift in two steps to avoid warning if long has 32 bits.  */
      cccc |= (cccc << 16) << 16;

    /* There are at least some bytes to set.
       No need to test for LEN == 0 in this alignment loop.  */
    while (dstp % OPSIZ != 0) {
      ((byte*)dstp)[0] = c;  // NOLINT
      dstp += 1;
      len -= 1;
    }

    /* Write 8 `op_t' per iteration until less than 8 `op_t' remain.  */
    xlen = len / (OPSIZ * 8);
    while (xlen > 0) {
      ((op_t*)dstp)[0] = cccc;  // NOLINT
      ((op_t*)dstp)[1] = cccc;  // NOLINT
      ((op_t*)dstp)[2] = cccc;  // NOLINT
      ((op_t*)dstp)[3] = cccc;  // NOLINT
      ((op_t*)dstp)[4] = cccc;  // NOLINT
      ((op_t*)dstp)[5] = cccc;  // NOLINT
      ((op_t*)dstp)[6] = cccc;  // NOLINT
      ((op_t*)dstp)[7] = cccc;  // NOLINT
      dstp += 8 * OPSIZ;
      xlen -= 1;
    }
    len %= OPSIZ * 8;

    /* Write 1 `op_t' per iteration until less than OPSIZ bytes remain.  */
    xlen = len / OPSIZ;
    while (xlen > 0) {
      ((op_t*)dstp)[0] = cccc;  // NOLINT
      dstp += OPSIZ;
      xlen -= 1;
    }
    len %= OPSIZ;
  }

  /* Write the last few bytes.  */
  while (len > 0) {
    ((byte*)dstp)[0] = c;  // NOLINT
    dstp += 1;
    len -= 1;
  }

  return dstpp;
}

static void BM_memset(benchmark::State& state) {
  char* str = new char[state.range(0)];
  for (auto _ : state) {
    memset(str, 'a', state.range(0));
    benchmark::ClobberMemory();
  }
  delete[] str;
}
static void BM_glibc_memset(benchmark::State& state) {
  char* str = new char[state.range(0)];
  for (auto _ : state) {
    glibc_memset(str, 'a', state.range(0));
    benchmark::ClobberMemory();
  }
  delete[] str;
}

static void BM_fill(benchmark::State& state) {
  char* str = new char[state.range(0)];
  for (auto _ : state) {
    std::fill(str, str + state.range(0), 'a');
    benchmark::ClobberMemory();
  }
  delete[] str;
}

static void BM_memset_simp(benchmark::State& state) {
  char* str = new char[state.range(0)];
  for (auto _ : state) {
    memset_simp(str, str + state.range(0), 'a');
    benchmark::ClobberMemory();
  }
  delete[] str;
}

static void BM_memset_unroll(benchmark::State& state) {
  char* str = new char[state.range(0)];
  for (auto _ : state) {
    memset_unroll(str, str + state.range(0), 'a');
    benchmark::ClobberMemory();
  }
  delete[] str;
}

BENCHMARK(BM_memset_simp)->RangeMultiplier(48)->Range(4, 1 << 30);
BENCHMARK(BM_memset_unroll)->RangeMultiplier(48)->Range(4, 1 << 30);

BENCHMARK(BM_fill)->RangeMultiplier(48)->Range(4, 1 << 30);
BENCHMARK(BM_memset)->RangeMultiplier(48)->Range(4, 1 << 30);
BENCHMARK(BM_glibc_memset)->RangeMultiplier(48)->Range(4, 1 << 30);

BENCHMARK_MAIN();
