#include <catch.hpp>

#include "libname/hello_world.h"

SCENARIO("Simple scenario") {
    GIVEN("A C++ project template") {
        WHEN("I get the hello world string") {
            auto hw = libname::helloWorld();
            THEN("It works!") {
                REQUIRE(hw == "Hello world!");
            }
        }
    }
}
