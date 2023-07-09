#include <string>
#include <string_view>
#include <iostream>
#include "include/option-register.h"
#include "include/unix.h"
#include "include/utils.h"

namespace Core {

OptionRegister::OptionRegister(typeOptHandlerMapper &&handlerMap) {
  handlerMapper = std::move(handlerMap);
}

OptionRegister::InputLine OptionRegister::analyzeOption(const std::string& str) const {
  auto strView = std::string_view(str);
  const auto equal = strView.find_first_of(' ');
  if (equal != std::string_view::npos) {
    const auto cmd = strView.substr(0, equal);
    const auto arg = strView.substr(equal + 1);
    return InputLine { std::string(cmd), std::make_optional(arg.data()) };
  } else {
    return InputLine { str, std::nullopt };
  }
}

void OptionRegister::parse(std::string& str) const {
  // Create a new process for running the command.
  pid_t pid;
  int processStatus;
  if ((pid = fork()) < 0) {
    Printer::reportError("Error forking a process.");  
  } else if (pid == 0) {
    // Analyze the input command.
    const auto inputLine = analyzeOption(str);
    const auto& op = handlerMapper.find(inputLine.cmd);
    if (op != handlerMapper.end()) {
      op->second();
      std::exit(EXIT_SUCCESS);
    } else {
      // Execute the line as a command.
      const auto execFile = inputLine.cmd.data();
      const auto ret = inputLine.arg.has_value() 
        ? execlp(execFile, execFile, inputLine.arg.value(), (char*) 0) 
        : execlp(execFile, execFile, (char*) 0);  
      if (ret < 0) Printer::reportError("Error executing the command - \"" + str + "\".", True);  
    }
  }
  if ((pid = waitpid(pid, &processStatus, 0)) < 0) {
    Printer::reportError("Error waiting for a child process.");
  }
}

}
