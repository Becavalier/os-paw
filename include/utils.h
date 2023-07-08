#ifndef	_UTILS_H
#define	_UTILS_H

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

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
  template<typename T> Printer& feed(const T& str) {
    const auto idx = feedCounter++ % columnSize;
    if (idx == 0) ss << '\n';
    ss << std::left << std::setw(columnWidthArr[static_cast<int>(idx)]) << str;
    return *this;
  }
};

#endif	/* _UTILS_H */
