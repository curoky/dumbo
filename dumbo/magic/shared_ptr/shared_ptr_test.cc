#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "shared_ptr.h"

TEST_CASE("[SharedPtrTest]: basic usage") {
  cry::SharedPtr<int> ptr(new int(1));
  REQUIRE(ptr.use_count() == 1);
  ptr.reset();
  REQUIRE(ptr.get() == nullptr);
  REQUIRE(ptr.use_count() == 0);

  cry::SharedPtr<int> ptr2(new int(1));
  ptr = ptr2;
  REQUIRE(ptr.use_count() == 2);
  REQUIRE(ptr2.use_count() == 2);

  ptr2.reset();
  REQUIRE(ptr.use_count() == 1);
  ptr.reset();
  REQUIRE(ptr.get() == nullptr);
  REQUIRE(ptr.use_count() == 0);
}
