#include "Bitstream.h"
#include "catch.hpp"
TEST_CASE("getOneBit")
{
    uint8_t data[1];
    BitstreamReader bs(data, 1);
    data[0] = 1 << 7;
    REQUIRE(0b1 == bs.get<1>());
}
