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

template<typename T>
inline void Misc::siga(const int sig, T&& h) {
  if (sigaction(sig, std::forward<T>(h), NULL) < 0) {
    std::exit(EXIT_FAILURE);
  }
}

void Misc::printAssistantInfo() {
  std::cout << "\n(🐈 os-paw 🐕)" << "\n\nBuilt at: " << BUILDSTAMP << "\n\n";
}

void Misc::setupSigHandlers() {
  struct sigaction sa {
    .sa_flags = 0,
    .sa_handler {
      [](int sigRecv) { 
        const auto item = sigNameMap.find(sigRecv);
        std::cout << (item != sigNameMap.end() ? item->second : "SIGERR") << std::endl;
        std::exit(EXIT_FAILURE); 
      }
    }
  };
  sigemptyset(&sa.sa_mask);
  Misc::siga(SIGILL, &sa);
  Misc::siga(SIGSEGV, &sa);
  Misc::siga(SIGBUS, &sa);
}

}
