#ifndef	_OPTION_REGISTER_H
#define	_OPTION_REGISTER_H

#include <string>
#include <optional>
#include <unordered_map>

namespace Core {

class OptionRegister {
  struct InputLine {
    std::string cmd;
    std::optional<const char*> arg;
  };
  using typeOptHandler = void(*)();
  using typeOptHandlerMapper = std::unordered_map<std::string, typeOptHandler>;
  typeOptHandlerMapper handlerMapper;
  InputLine analyzeOption(const std::string&) const;
 public:
  OptionRegister(typeOptHandlerMapper &&);
  void parse(std::string&) const;
};

}

#endif	/* _OPTION_REGISTER_H */
