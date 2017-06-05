#include "catch.hpp"
#include "Memory.h"

// create test memory object
Memory mem(1,1);

// check that 
TEST_CASE("check memory object is created") {
    REQUIRE(mem.ready() == true);
}
