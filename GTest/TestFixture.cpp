#include <iostream>
#include <gtest/gtest.h>
#include <vector>

class Stack {
    private:
        std::vector<int> stack {};
    public: 
        void push(int data) { stack.push_back(data); }
        int pop() {
            if (!stack.empty()) {
                int val = stack.back();
                stack.pop_back();
                return val;
            } else {
                return -1;
            }
        }
        int size() { return stack.size(); }
};

class StackTest: public testing::Test {
    public:
    Stack s1;
    void SetUp() override {
        int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int num: arr)
            s1.push(num);
    }
    void TearDown() override {}
};

TEST_F(StackTest, LastPopTest) {
    int lastElement = 9;
    while (lastElement != 1)
        EXPECT_EQ(s1.pop(), lastElement--);
}

TEST_F(StackTest, StackSizeTest) {
    int expected = 9;
    while (s1.size() > 0) {
        EXPECT_EQ(s1.pop(), expected--); 
    }
    EXPECT_EQ(s1.pop(), -1); 
}

/*
    g++ TestFixture.cpp -o test_exec -lgtest -lgtest_main -pthread && time ./test_exec && rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
