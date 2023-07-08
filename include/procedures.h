#ifndef	_PROCEDURES_H
#define	_PROCEDURES_H

#include <include/utils.h>

namespace Core {
  class Procedures {
    static void printSysResult(unsigned char, const char*, const char*, Printer&);
   public:
    static void printSysConf();
  };
}

#endif	/* _PROCEDURES_H */
