#include <catch2/catch.hpp>

int testing(int n)
{
    return n*n;
}

TEST_CASE("basic testing test", "[testtag]")
{
    REQUIRE(testing(5) == 25);
    REQUIRE(testing(3) == 9);
    REQUIRE(testing(2) == 4);
}