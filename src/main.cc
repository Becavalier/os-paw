#include <iostream>
#include <string>
#include "include/option-register.h"
#include "include/unix.h"
#include "include/procedures.h"
#include "include/utils.h"

using namespace Core;

int main(int argc, char* argv[]) {
  const auto optionHandlers = OptionRegister({
    {  "sysconf", Procedures::printSysConf }
  });
  // Set up the main loop.
  Misc::printAssistantInfo();
  std::string input;
	while (true) {
    std::cout << "\U0001F43E % ";
    std::getline(std::cin, input);
    optionHandlers.parse(input);
	}
  return 0;
}