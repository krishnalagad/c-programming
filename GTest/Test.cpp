#include <gtest/gtest.h>
#include "Math.hpp"

// Test case for the add function
TEST(TestSuite1, PositiveNumbers) {
    EXPECT_EQ(3, add(1, 2));
}
TEST(TestSuite1, NegativeNumbers) {
    EXPECT_EQ(-3, add(-1, -2));
}
TEST(TestSuite1, PositiveAndNegativeNumbers) {
    // EXPECT_EQ(0, add(-1, 1));
    ASSERT_TRUE(0 == add(-1, 1));
}

// Test case for the subtract function
TEST(TestSuite2, SubPosRes) {
    EXPECT_EQ(10, subtract(20, 10));
}
TEST(TestSuite2, SubNegRes) {
    EXPECT_EQ(-10, subtract(-20, -10));
}
TEST(TestSuite2, SubPosNegRes) {
    EXPECT_EQ(-30, subtract(-20, 10));
}

/*
    g++ -std=c++11 -o app Test.cpp Math.cpp -lgtest -lgtest_main -pthread && time ./app && rm app
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
