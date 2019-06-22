#include <boost/algorithm/string/join.hpp>       // for join
#include <boost/range/adaptor/argument_fwd.hpp>  // for forwarder
#include <boost/range/adaptor/map.hpp>
#include <boost/range/adaptor/transformed.hpp>  // for transformed_range, operator|, transform_holder, transformed
#include <boost/range/algorithm/copy.hpp>
#include <catch2/catch.hpp>  // for AssertionHandler, SourceLineInfo, StringRef, operator""_catch_sr, REQUIRE, TEST_CASE

#include <list>
#include <map>
#include <set>
#include <string>  // for basic_string, operator==, string, to_string
#include <vector>  // for vector

TEST_CASE("[Range]: copy") {
  std::map<int, int> foo = {{1, 2}, {2, 3}};
  std::vector<int> keys;
  std::list<int> valus;
  boost::copy(foo | boost::adaptors::map_keys, std::back_inserter(keys));
  boost::copy(foo | boost::adaptors::map_values, std::back_inserter(valus));
  REQUIRE(keys == std::vector<int>({1, 2}));
  REQUIRE(valus == std::list<int>({2, 3}));
}

TEST_CASE("[Range]: transformed") {
  std::vector<double> nubs{1.1, 2.2, 3.3, 4.4};
  std::string nubs_str = boost::algorithm::join(
      nubs | boost::adaptors::transformed(static_cast<std::string (*)(double)>(std::to_string)),
      ", ");
  REQUIRE(nubs_str == "1.100000, 2.200000, 3.300000, 4.400000");
}
