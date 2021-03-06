#include "dumbo/trace/trace.h"

#include <catch2/catch.hpp>

#include <thread>

void record1() {
  tt_emit("accept", "1");
  tt_emit("read", "1");
  tt_emit("write", "1");
}

void record2() {
  tt_emit("accept", "2");
  tt_emit("read", "2");
  tt_emit("write", "2");
}

TEST_CASE("[Trace]: basic test") {
  tt_emit("accept", "3");
  tt_emit("read", "3");
  tt_emit("write", "3");

  std::thread t1(record1);
  std::thread t2(record2);
  t1.join();
  t2.join();
}
