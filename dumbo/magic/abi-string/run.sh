#!/usr/bin/env bash
set -xeuo pipefail

export PATH=/home/linuxbrew/.linuxbrew/opt/gcc@4.9/bin:/home/linuxbrew/.linuxbrew/opt/gcc@10/bin:$PATH

g++-4.9 -o gcc4-string sizeof-string.cc
g++-10 -o gcc10-string sizeof-string.cc

./gcc4-string
./gcc10-string

rm -rf gcc4-string gcc10-string
