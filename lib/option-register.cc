#include <string>
#include <iostream>
#include "include/option-register.h"

namespace Core {
  constexpr int COMMAND_HEAD_IDX = 1;
  OptionRegister::OptionRegister(typeOptHandlerMapper &&handlerMap) {
    handlerMapper = std::move(handlerMap);
  }

  void OptionRegister::parse(const int argc, const char *const *const argv) const {
    if (argc > 1) {
      std::string command(argv[COMMAND_HEAD_IDX]); 
      if (handlerMapper.contains(command)) {
        const auto& cb = handlerMapper.at(command);
        cb();
      }
    }
  }
}
