#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <include/procedures.h>
#include <include/unix.h>
#include <include/macros.h>
#include <include/utils.h>

#define POSIX_CPU_INFO

namespace Core {

void Procedures::printSysResult(unsigned char option, const char* label, const char* desc, Printer &printer) {
  printer.boldOn().feed(label).boldOff();
  errno = 0;  // Reset errno first.
  const auto configVal = sysconf(option);
  if (configVal < 0) {
    if (errno != 0) {
      printer.feed(errno == EINVAL ? "N/A" : "Error");  // Invalid argument.
    } else {
      printer.feed(strstr(label, "POSIX") != nullptr ? "✖" : "No Limit");
    }
  } else {
    printer.feed(configVal);
  }
  printer.feed(desc);
}

void Procedures::printSysConf() {
  Printer printer;
  std::cout << "\nOption / Value / Description:\n\n";
  std::cout << "* Please note the config value is only FYI, maybe it's not consistent with the implementation.\n";
  printer.setLineColumnWidth({ 28, 10, 90 });
  ITERATE_SYSCONF(printSysResult, printer);
  printer.output();
}

void Procedures::printProcessorInfo() {
  #if defined(__x86_64__) && !defined(POSIX_CPU_INFO)
    #define INFO_ARR_SIZE 33
    #define ITER_BRAND_STR(V, BUF) \
      V("0x80000002", BUF) \
      V("0x80000003", BUF) \
      V("0x80000004", BUF)
    #define FETCH_CPU_INFO(CODE, BUF) \
      __asm__( \
        "movl $" CODE ", %%eax\n\t" \
        "cpuid\n\t" \
        "movl %%eax, %0\n\t" \
        "movl %%ebx, 0x04 + %0\n\t" \
        "movl %%ecx, 0x08 + %0\n\t" \
        "movl %%edx, 0x0c + %0" \
        : "=m" (BUF)); \
      std::cout << BUF;
    uint8_t buffer[INFO_ARR_SIZE];
    buffer[INFO_ARR_SIZE - 1] = '\0';
    ITER_BRAND_STR(FETCH_CPU_INFO, buffer)
    std::cout << std::endl;
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
      Printer::reportError("unable to detect CPU information.");
    }
  #endif
}

}
