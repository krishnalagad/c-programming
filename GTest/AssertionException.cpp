#include <gtest/gtest.h>

int getDivision(int num1, int num2) {
    if (num2 == 0)
        throw std::runtime_error("Cannot be divided by zero!!");
    return num1 / num2;
}

TEST(Exception, Check1) {
    ASSERT_THROW(getDivision(10, 0), std::runtime_error);
}

/*
    g++ AssertionException.cpp -o test_exec -lgtest -lgmock -pthread &&
    time ./test_exec &&
    rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
