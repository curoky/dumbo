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
# @file: iwyu.sh
# -----------------------------------------------------------------------------

set -xeuo pipefail

IWYU_MAP=$(cd "$(dirname "$0")" && pwd)/mappings
EXEC_ROOT=$(bazel info execution_root)

# gen compile_commands.json
bazel build //script/iwyu:example_compdb --check_visibility=false

# patch compile_commands.json
CMDS_PATH=$(bazel info bazel-bin)/script/iwyu/compile_commands.json
sed -i 's/-fno-canonical-system-headers//g' $CMDS_PATH
sed -i 's/-Wunused-but-set-parameter/-Wunused-parameter/g' $CMDS_PATH
sed -i 's/-Wno-free-nonheap-object/-Wno-sequence-point/g' $CMDS_PATH
sed -i 's/-Wno-free-nonheap-object/-Wno-sequence-point/g' $CMDS_PATH
sed -i 's%__EXEC_ROOT__%/shm/bazel/execroot/com_github_curoky_dumbo%g' $CMDS_PATH
cp -f $CMDS_PATH $EXEC_ROOT/compile_commands.json

# direct gen
iwyu_tool.py -j 190 -p $EXEC_ROOT $EXEC_ROOT/dumbo -- \
  -Xiwyu --mapping_file=$IWYU_MAP/boost-all-private.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/boost-all.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/boost-extra.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/gflags.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/glog.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/gtest.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/libcxx-extra.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/libcxx.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/libstdcpp.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/libunwind.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/llvm.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/openssl.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/system-linux.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/nlohmann_json.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/cpr.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/cpp-taskflow.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/fmt.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/jsoncpp.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/msgpack.imp \
  -Xiwyu --mapping_file=$IWYU_MAP/taro.imp \
  -Xiwyu --transitive_includes_only \
  -Xiwyu --max_line_length=160 \
  -Xiwyu --cxx17ns >iwyu.out

fix_includes.py --comments -b --reorder -p $EXEC_ROOT <iwyu.out
