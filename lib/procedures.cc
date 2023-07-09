#include <iostream>
#include <include/procedures.h>
#include <include/unix.h>
#include <include/macros.h>
#include <include/utils.h>

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

}
