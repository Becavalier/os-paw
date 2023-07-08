#ifndef	_OPTION_REGISTER_H
#define	_OPTION_REGISTER_H

#include <string>
#include <unordered_map>

namespace Core {
  class OptionRegister {
    using typeOptHandlerMapper = std::unordered_map<std::string, void (*)()>;
    typeOptHandlerMapper handlerMapper;
    
   public:
    OptionRegister(typeOptHandlerMapper &&);
    void parse(const int argc, const char *const *const argv) const;
  };
}

#endif	/* _OPTION_REGISTER_H */
