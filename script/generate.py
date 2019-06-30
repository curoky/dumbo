#!/usr/bin/env python3
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

import os
import sys
import logging
import subprocess
import shutil

WORKSPACE = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))

print(f"WORKSPACE: {WORKSPACE}")

FBTHRIFT_BIN_PATH = '/home/linuxbrew/.linuxbrew/opt/fbthrift/bin/thrift1'
THRIFT_BIN_PATH = '/home/linuxbrew/.linuxbrew/opt/thrift@0.13.0/bin/thrift'


def clear_path(path: str):
    if os.path.isdir(path):
        logging.debug("remove directory: %s", path)
        shutil.rmtree(path)
    os.mkdir(path)


def gen_thrift(path):
    out = os.path.dirname(path)
    gen_path = os.path.join(out, 'gen-cpp')
    clear_path(gen_path)
    cmd = '%s --gen cpp -o %s %s' % (THRIFT_BIN_PATH, out, path)
    logging.debug("gen_thrift: %s", cmd)
    subprocess.call(cmd, shell=True)
    return 0


def gen_fbthrift(path):
    out = os.path.dirname(path)
    gen_path = os.path.join(out, 'gen-cpp2')
    clear_path(gen_path)
    include_prefix = out.replace(WORKSPACE + '/', '')
    # args:
    # json,frozen2,optionals,coroutines,nimble,reflection,terse_writes
    # stack_arguments,sync_methods_return_try,no_getters_setters,process_in_event_base
    # deprecated_client_streams,deprecated_server_streams,deprecated_enforce_required,deprecated_public_fields
    # include_prefix
    cmd = '%s -gen mstch_cpp2:include_prefix=%s -o %s %s' % (FBTHRIFT_BIN_PATH, include_prefix, out,
                                                             path)
    logging.debug("gen_fbthrift: %s", cmd)
    subprocess.call(cmd, shell=True)
    return 0


def main():
    gen_thrift(os.path.join(WORKSPACE, 'dumbo/scaffold/serialization/thrift/mock.thrift'))
    gen_fbthrift(os.path.join(WORKSPACE, 'dumbo/scaffold/serialization/fbthrift/mock.thrift'))
    return 0


if __name__ == "__main__":
    # logging.basicConfig(level=logging.DEBUG)
    logging.basicConfig(level=logging.INFO)
    sys.exit(main())
