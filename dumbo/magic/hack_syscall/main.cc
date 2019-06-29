#include <stdlib.h>

#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "time: " << time(NULL) << std::endl;
  std::cout << "rand: " << rand() << std::endl;
  std::cout << "rand_r: " << rand_r(NULL) << std::endl;
  return 0;
}
