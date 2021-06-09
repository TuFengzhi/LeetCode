#define CTEST_MAIN
// #define CTEST_SEGFAULT
#define CTEST_NO_COLORS
// #define CTEST_COLOR_OK

#include <iostream>

#include "build/googletest-src/googletest/include/gtest/gtest.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    // Runs all tests using Google Test.
    return RUN_ALL_TESTS();
}