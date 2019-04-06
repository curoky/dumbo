#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "cow_string.h"

TEST_CASE("[CowStringTest]: basic usage") {
  cry::CowString str(5, 'a');
  REQUIRE(str.use_count() == 1);
  REQUIRE(str.data() == std::string("aaaaa"));

  cry::CowString str_cp = str;
  REQUIRE(str.use_count() == 2);
  REQUIRE(str_cp.use_count() == 2);

  str_cp[0] = 'b';
  REQUIRE(str_cp.use_count() == 1);
  REQUIRE(str_cp.data() == std::string("baaaa"));
}
