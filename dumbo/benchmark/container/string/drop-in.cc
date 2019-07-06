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

#include <benchmark/benchmark.h>  // for State, Benchmark, BENCHMARK_TEMPLATE, ClobberMemory, DoNotOptimize, BENCHMARK_MAIN
#include <folly/FBString.h>  // for fbstring

#include <string>  // for string

template <class String>
void BM_string_construct(benchmark::State& state) {
  for (auto _ : state) {
    {
      String str(state.range(0), 'a');
      benchmark::DoNotOptimize(str);
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

template <class String>
void BM_string_reserve(benchmark::State& state) {
  for (auto _ : state) {
    {
      String str;
      str.reserve(state.range(0));
      benchmark::DoNotOptimize(str);
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

template <class String>
void BM_string_copy(benchmark::State& state) {
  String str(state.range(0), 'a');
  for (auto _ : state) {
    {
      String v = str;
      benchmark::DoNotOptimize(v);
      benchmark::ClobberMemory();
      state.PauseTiming();
    }
    state.ResumeTiming();
  }
}

// clang-format off
BENCHMARK_TEMPLATE(BM_string_construct, std::string)->RangeMultiplier(64)->Range(1, 1 << 24);
BENCHMARK_TEMPLATE(BM_string_construct, folly::fbstring)->RangeMultiplier(64)->Range(1, 1 << 24);
BENCHMARK_TEMPLATE(BM_string_reserve, std::string)->RangeMultiplier(64)->Range(1, 1 << 24);
BENCHMARK_TEMPLATE(BM_string_reserve, folly::fbstring)->RangeMultiplier(64)->Range(1, 1 << 24);
BENCHMARK_TEMPLATE(BM_string_copy, std::string)->RangeMultiplier(64)->Range(1, 1 << 24);
BENCHMARK_TEMPLATE(BM_string_copy, folly::fbstring)->RangeMultiplier(64)->Range(1, 1 << 24);
// clang-format on

BENCHMARK_MAIN();
