#include <begin.hpp>                             // for begin
#include <boost/algorithm/string/join.hpp>       // for join
#include <boost/range/adaptor/argument_fwd.hpp>  // for forwarder
#include <boost/range/adaptor/map.hpp>           // for select_first_range, select_second_mutable_range, operator|, map_keys, map_keys_forwarder, map_values
#include <boost/range/adaptor/transformed.hpp>   // for transformed_range, operator|, transform_holder, transformed
#include <boost/range/algorithm/copy.hpp>        // for copy
#include <catch2/catch.hpp>                      // for AssertionHandler, operator""_catch_sr, SourceLineInfo, StringRef, REQUIRE, TEST_CASE
#include <end.hpp>                               // for end
#include <iterator_facade.hpp>                   // for operator!=
#include <algorithm>                             // for copy, equal
#include <iterator>                              // for back_insert_iterator, back_inserter
#include <list>                                  // for list, operator==, operator!=
#include <map>                                   // for map, operator==
#include <string>                                // for basic_string, allocator, operator==, string, to_string
#include <vector>                                // for vector, operator==

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
