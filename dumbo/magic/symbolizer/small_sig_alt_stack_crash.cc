
/*
*** Aborted at 1612434803 (Unix time, try 'date -d @1612434803') ***
*** Signal 4 (SIGILL) (0x5577bcd7cee3) received by PID 590679 (pthread TID 0x7f7f9efaa400) (linux
TID 590679) (code: illegal operand), stack trace: *** (error retrieving stack trace) [1]    590679
illegal hardware instruction (core dumped)  bazel run
dumbo/magic/symbolizer:small_sig_alt_stack_crash
*/

#include <folly/experimental/symbolizer/SignalHandler.h>
#include <signal.h>

#include <array>

namespace {
std::array<char, 8192> stack;
}

int main() {
  stack_t ss;
  ss.ss_sp = stack.data();
  ss.ss_size = stack.size();
  ss.ss_flags = 0;
  sigaltstack(&ss, nullptr);

  folly::symbolizer::installFatalSignalHandler();
  __builtin_trap();
  return 0;
}
