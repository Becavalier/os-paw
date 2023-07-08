#include <iostream>
#include <string>
#include "include/option-register.h"
#include "include/unix.h"
#include "include/procedures.h"

int main(int argc, char* argv[]) {
  const auto optionHandlers = Core::OptionRegister({
    { 
      "sysconf", 
      []() {
        Core::Procedures::printSysConf();
      } 
    }
  });
  optionHandlers.parse(argc, argv);
  return 0;
}