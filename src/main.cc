#include <iostream>
#include "include/unix.h"

int main(int argc, char** argv) {
  std::cout << getuid() << std::endl;
  return 0;
}