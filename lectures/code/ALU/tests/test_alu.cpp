#include "catch.hpp"
#include "ALU.h"

// create test alu object
ALU alu;

// check that addition works
TEST_CASE("check addition") {
    alu.execute(10,10,1);
    REQUIRE(alu.read_valid() == 20);
    REQUIRE(alu.carry() == false);
}

TEST_CASE("check roll-over case") {
    alu.execute(0xffff,1,1);
    REQUIRE(alu.read_valid() == 0);
    REQUIRE(alu.carry() == true);
}


