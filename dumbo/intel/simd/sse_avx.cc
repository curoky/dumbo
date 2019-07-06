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

// https://zhou-yuxin.github.io/articles/2017/%E4%BD%BF%E7%94%A8Intel%20SSE-AVX%E6%8C%87%E4%BB%A4%E9%9B%86%EF%BC%88SIMD%EF%BC%89%E5%8A%A0%E9%80%9F%E5%90%91%E9%87%8F%E5%86%85%E7%A7%AF%E8%AE%A1%E7%AE%97/index.html

#include <immintrin.h>  // for _mm256_load_ps, __m256, _mm256_dp_ps
#include <smmintrin.h>  // for _mm_dp_ps
#include <stdio.h>      // for printf
#include <xmmintrin.h>  // for _mm_load_ps, __m128, _mm_add_ps

#include <cstdint>  // for uint32_t

float vector_dot(uint32_t len, const float* a, const float* b) {
  double sum = 0;
  uint32_t i = 0;
  uint32_t end = len & (~3);
  for (; i < end; i += 4) {
    __m128 A = _mm_load_ps(a + i);
    __m128 B = _mm_load_ps(b + i);
    __m128 C = _mm_dp_ps(A, B, 0xf1);
    sum += C[0];
  }
  for (; i < len; i++) sum += a[i] * b[i];
  return static_cast<float>(sum);
}

float vector_dot2(uint32_t len, const float* a, const float* b) {
  double sum = 0;
  uint32_t i = 0;
  uint32_t end;
  end = len & (~7);
  for (; i < end; i += 8) {
    __m256 tmp = _mm256_dp_ps(_mm256_load_ps(a + i), _mm256_load_ps(b + i), 0xf1);
    sum += tmp[0] + tmp[4];
  }
  end = len & (~3);
  for (; i < end; i += 4) {
    __m128 C = _mm_dp_ps(_mm_load_ps(a + i), _mm_load_ps(b + i), 0xf1);
    sum += C[0];
  }
  for (; i < len; i++) sum += a[i] * b[i];
  return (float)sum;
}

int main() {
  float __attribute__((aligned(16))) a[4] = {1, 3, 5, 7};
  float __attribute__((aligned(16))) b[4] = {5, 10, 15, 20};
  __m128 A = _mm_load_ps(a);
  __m128 B = _mm_load_ps(b);
  __m128 C = _mm_add_ps(A, B);
  for (int i = 0; i < 4; i++) printf("%f ", C[i]);
  printf("\n");
  return 0;
}
