#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <functional>

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class DatabaseConnect {
    public:
        virtual bool login(std::string username, std::string password) { return true; }
        virtual bool logout(std::string username) {return true; }
        virtual int fetchRecord() { return -1; }
};

class MockDB: public DatabaseConnect {
    public:
        MOCK_METHOD0(fetchRecord, int());
        MOCK_METHOD1(logout, bool(std::string username));
        MOCK_METHOD2(login, bool(std::string username, std::string password));

};

using DatabaseRef = std::reference_wrapper<DatabaseConnect>;
class MyDatabase {
    DatabaseRef dbC;
    public:
        MyDatabase(DatabaseRef _dbC): dbC(_dbC) {}
        int Init(std::string username, std::string password) {
            if (dbC.get().login(username, password) !=true) {
                if (dbC.get().login(username, password) != true) {
                    std::cout << "DB FAILURE 2nd TIME!!" << std::endl; return -1;
                } else {
                    std::cout << "DB SUCCESS ON 2nd ATTEMPT!!" << std::endl; return 1;
                } 
            } else {
                std::cout << "DB SUCCESS!!" << std::endl; return 1;
            }
        }
};

TEST(DB_Test, LoginTest) {
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);
    EXPECT_CALL(mdb, login(_, _))
        .Times(AtLeast(1))
        .WillRepeatedly(Return(true));

    // Act
    int response = db.Init("krishna", "lagad");

    // Asssert
    EXPECT_EQ(response, 1);
}

TEST(DB_Test, LoginFailure) {
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);
    EXPECT_CALL(mdb, login(_, _))
        .Times(AtLeast(2))
        .WillRepeatedly(Return(false));

    // Act
    int response = db.Init("krishna", "lagad");

    // Assert
    EXPECT_EQ(response, -1);
}

/*
    g++ Mock.cpp -o test_exec -lgtest -lgtest_main -pthread -lgmock -lgmock_main && time ./test_exec && rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
