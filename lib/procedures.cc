#include <iostream>
#include <fstream>
#include <cstdio>
#include <include/procedures.h>
#include <include/unix.h>
#include <include/macros.h>
#include <include/utils.h>

#define POSIX_CPU_INFO

namespace Core {

void Procedures::printSysResult(unsigned char option, const char* label, const char* desc, Printer &printer) {
  printer.feed(label).feed(desc);
  errno = 0;  // Reset errno first.
  const auto configVal = sysconf(option);
  if (configVal < 0) {
    if (errno != 0) {
      printer.feed(errno == EINVAL ? "N/A" : "Error");  // Invalid argument.
    } else {
      printer.feed("No Limit");
    }
  } else {
    printer.feed(configVal);
  }
}

void Procedures::printSysConf() {
  Printer printer;
  printer.setLineColumnWidth({ 17, 90, 15 });
  printer.feed("[Option]").feed("[Desc]").feed("[Value]\n");
  ITERATE_SYSCONF(printSysResult, printer);
  printer.output();
}

void Procedures::printProcessorInfo() {
  #if defined(__x86_64__) && !defined(POSIX_CPU_INFO)
    // TODO.
  #elif defined(__aarch64__) && !defined(POSIX_CPU_INFO)
    uint64_t mainIdRegVal;
    __asm__("mrs %0, MIDR_EL1" : "=r" (mainIdRegVal));  // This requires EL1 level.
  #else
    // Fallback to the default approach.
    std::ifstream in { "/proc/cpuinfo", std::ifstream::in };
    if (in.is_open() && in.good()) {
      char c;
      while (in.get(c)) {
        std::cout << c << std::endl;
      }
    } else {
      Printer::reportError("Not able to detect the CPU information.");
    }
  #endif
}

}
