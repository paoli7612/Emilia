#ifndef LOG_ERROR_HH
#define LOG_ERROR_HH

#include <string>
#include <iostream>

inline const void LogErrorV(const std::string Str) {
  std::cerr << Str << std::endl;
}

#endif // !LOG_ERROR_HH