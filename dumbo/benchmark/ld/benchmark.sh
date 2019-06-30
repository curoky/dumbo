#!/usr/bin/env bash
# Copyright 2020 curoky(cccuroky@gmail.com).
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# -----------------------------------------------------------------------------
# @file: benchmark.sh
# -----------------------------------------------------------------------------

function gen_srcs() {
  mkdir -p srcs

  rm -rf srcs/a.cc
  for i in {1..8000}; do
    echo "namespace {class A_${i} {};}" >>srcs/a.cc
  done

  echo 'int main() { return 0; }' >srcs/main.cc
  echo '''
rule compile
  command = gcc -c $in -o $out
''' >build.ninja

  for i in {1..6000}; do
    cp srcs/a.cc srcs/a_${i}.cc

    echo "build srcs/a_${i}.o: compile srcs/a_${i}.cc" >>build.ninja
  done
  echo "build srcs/main.o: compile srcs/main.cc" >>build.ninja

}

gen_srcs
ninja -j 30

time gcc srcs/a_{1..6000}.o srcs/main.o -o main
time gcc -fuse-ld=gold srcs/a_{1..6000}.o srcs/main.o -o main
time gcc -fuse-ld=lld srcs/a_{1..6000}.o srcs/main.o -o main
