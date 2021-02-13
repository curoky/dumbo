// #include <folly/experimental/symbolizer/Symbolizer.h>
// #define BOOST_STACKTRACE_USE_WINDBG_CACHED
#include <folly/Format.h>
#define BOOST_STACKTRACE_USE_BACKTRACE
#define BOOST_STACKTRACE_USE_ADDR2LINE

#include <boost/stacktrace.hpp>
#include <backtrace.h>
#include <iostream>

void func0(int a) {
  boost::stacktrace::stacktrace st;
  for (boost::stacktrace::frame frame : st) {
    auto line = folly::sformat("[{}]-{}:{}:{}", frame.address(), frame.source_file(),
                               frame.source_line(), frame.name());
    std::cout << line << std::endl;
  }

  std::cout << "a: " << a << std::endl;
}

void func1(int b) { func0(b); }

inline void func2(int c) { func1(c); }

int main(int argc, char const *argv[]) {
  func2(1);
  return 0;
}
