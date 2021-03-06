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

#include <stdlib.h>  // for rand, rand_r, NULL
#include <time.h>    // for time

#include <iostream>  // for operator<<, basic_ostream::operator<<, endl, basic_ostream, basic_ostream<>::__ostream_type, cout, ostream

int main(int argc, char const *argv[]) {
  std::cout << "time: " << time(NULL) << std::endl;
  std::cout << "rand: " << rand() << std::endl;  // NOLINT
  std::cout << "rand_r: " << rand_r(NULL) << std::endl;
  return 0;
}
