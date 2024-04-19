#include <iostream>
#include <gtest/gtest.h>

class UnitTest {
    private:
        std::string name;
    public:
        UnitTest() = delete;
        UnitTest(std::string _name): name(_name) {}
        ~UnitTest() = default;

        std::string getName() const { return name; }
};

TEST(UnitTest, IncrementInt) {
    // Arrangement
    int num = 10;
    int incrementVal = 5;

    // Act
    num += incrementVal;

    // Assert
    ASSERT_EQ(15, num);
}

TEST(UnitTest, StringValue) {
    // Arrangement
    UnitTest ut("Krishna");

    // Act
    std::string value = ut.getName();

    // Assert
    ASSERT_STREQ(value.c_str(), "Krishna");
}

/*
    g++ UnitTest.cpp -o test_exec -lgtest -lgtest_main -pthread && time ./test_exec && rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
