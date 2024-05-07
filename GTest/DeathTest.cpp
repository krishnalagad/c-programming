#include <gtest/gtest.h>

void funcDeathTest() {
    std::cerr << "Bad thing happened!!";
    exit(1);
}

TEST(DeathTest, Check1) {
    EXPECT_DEATH(funcDeathTest(), "Bad thing happened!!");
}

/*
    g++ DeathTest.cpp -o test_exec -lgtest -lgmock -pthread &&
    time ./test_exec --test_filter=DeathTest.Check1 &&
    rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
