#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>
#include "LibraryCode.hpp"

class ValidatorFixture: public testing::TestWithParam<int> {
    protected:
        Validator validator {5,10};
        void SetUp() override {}
        void TearDown() override {}
};

TEST_P(ValidatorFixture, TestInRange) {
    // Arrange
    int value = GetParam();
    // Act
    bool result = validator.inRange(value);
    // Assert
    ASSERT_TRUE(result);
}

INSTANTIATE_TEST_CASE_P(InRangeValues, ValidatorFixture, 
                            testing::Values(4,5,6,7,9,10));

/*
    g++ TestRunner.cpp LibraryCode.cpp -o test_exec -lgtest -lgtest_main -lgmock -lgmock_main -pthread &&
    time ./test_exec &&
    rm test_exec 
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
