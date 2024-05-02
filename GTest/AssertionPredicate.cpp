#include <gtest/gtest.h>
#include <functional>

std::function<bool(int)> evenFunc = [](int num){ return num % 2 == 0; };
auto numGreatFunc = [](int num1, int num2){ return num1 > num2; };

TEST(evenFunc, 23) {
    EXPECT_PRED1(evenFunc, 68);
}
TEST(Predicate, Check1) {
    EXPECT_PRED2(numGreatFunc, 10, 3);
}

/*
    g++ AssertionPredicate.cpp -o test_exec -pthread -lgtest -lgmock &&
    time ./test_exec &&
    rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
