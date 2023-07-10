#ifndef	_UTILS_H
#define	_UTILS_H

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <string>

namespace Core {

constexpr std::true_type True {};
constexpr std::false_type False {};

class Printer {
  std::vector<int> columnWidthArr;
  std::stringstream ss;
  size_t columnSize = 0;
  size_t feedCounter = 0;
 public:
  Printer() = default;

  inline void setLineColumnWidth(std::vector<int>&& v) {
    columnSize = v.size();
    columnWidthArr = std::move(v);
  }

  inline void output() const {
    std::cout << ss.str() << "\n\n";
  }

  template<typename T, typename K = std::false_type>
  static constexpr void reportError(T&& msg, K exit = False) {
    std::cerr << "[!] " << std::forward<T>(msg) << std::endl;
    if constexpr (exit) std::exit(EXIT_FAILURE);
  }

  template<typename T> 
  Printer& feed(const T& str) {
    const auto idx = feedCounter++ % columnSize;
    if (idx == 0) ss << '\n';
    ss << std::left << std::setw(columnWidthArr[static_cast<int>(idx)]) << str;
    return *this;
  }
};

class Misc {
  static const std::unordered_map<int, std::string> sigNameMap;
 public:
  static void printAssistantInfo();
  static void setupSigHandlers();
};

}

#endif	/* _UTILS_H */
