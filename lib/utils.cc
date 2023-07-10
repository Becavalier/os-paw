#include <iostream>
#include <include/utils.h>
#include <include/unix.h>

#define BUILDSTAMP (__DATE__ " " __TIME__)

namespace Core {

const std::unordered_map<int, std::string> Misc::sigNameMap {
  { SIGILL, "SIGILL" },
  { SIGSEGV, "SIGSEGV" },
  { SIGBUS, "SIGBUS" },
};

void Misc::printAssistantInfo() {
  std::cout << "\n(🐈 os-paw 🐕)" << "\n\nBuilt at: (" << BUILDSTAMP << ')' << "\n\n";
}

void Misc::setupSigHandlers() {
  struct sigaction sa;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sa.sa_handler = [](int sigRecv) { 
    const auto item = sigNameMap.find(sigRecv);
    std::cout << (item != sigNameMap.end() ? item->second : "SIGERR") << std::endl;
    std::exit(EXIT_FAILURE); 
  };
  if (sigaction(SIGILL, &sa, NULL) < 0) {
    std::exit(EXIT_FAILURE);
  }
}

}
