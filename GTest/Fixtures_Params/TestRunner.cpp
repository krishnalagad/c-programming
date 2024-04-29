#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include <tuple>
#include <iostream>
#include "LibraryCode.hpp"

using Tuple = std::tuple<int, bool>;
class ValidatorFixture: public testing::TestWithParam<Tuple> {
    protected:
        Validator validator {5,10};
        void SetUp() override {}
        void TearDown() override {}
};

TEST_P(ValidatorFixture, TestInRange) {
    // Arrange
    Tuple tuple = GetParam();
    int value = std::get<0>(tuple);
    bool expectedFlag = std::get<1>(tuple);
    std::cout << "value: " << value << "  " << "flag: " << expectedFlag << std::endl;
    // Act
    bool result = validator.inRange(value);
    // Assert
    ASSERT_EQ(result, expectedFlag);
}

INSTANTIATE_TEST_CASE_P(InRangeValues, ValidatorFixture, testing::Values(
    std::make_tuple(4, false),
    std::make_tuple(5, true),
    std::make_tuple(6, true),
    std::make_tuple(7, true),
    std::make_tuple(9, true),
    std::make_tuple(10, true),
    std::make_tuple(11, false),
    std::make_tuple(100, false),
    std::make_tuple(-234, false)
));

/*
    g++ TestRunner.cpp LibraryCode.cpp -o test_exec -lgtest -lgtest_main -lgmock -lgmock_main -pthread &&
    time ./test_exec &&
    rm test_exec 
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
