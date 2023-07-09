#include <iostream>
#include <include/utils.h>

#define BUILDSTAMP (__DATE__ " " __TIME__)

namespace Core {

void Misc::printAssistantInfo() {
  std::cout << "\n(🐈 os-paw 🐕)" << " ,built at: (" << BUILDSTAMP << ')' << "\n\n";
}

}
