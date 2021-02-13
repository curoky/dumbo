#include <folly/experimental/symbolizer/SignalHandler.h>

/*
*** Aborted at 1612434399 (Unix time, try 'date -d @1612434399') ***
*** Signal 4 (SIGILL) (0x5652e5fffc78) received by PID 573792 (pthread TID 0x7f4769aed400) (linux
TID 573792) (code: illegal operand), stack trace: *** (error retrieving stack trace) [1]    573792
illegal hardware instruction (core dumped)  bazel-bin/dumbo/magic/symbolizer/crash
*/
int main() {
  folly::symbolizer::installFatalSignalHandler();
  __builtin_trap();
}
