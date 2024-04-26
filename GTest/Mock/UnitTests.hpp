#ifndef UNITTESTS_HPP
#define UNITTESTS_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MockDB.hpp"
#include "MyDatabase.hpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

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
        .Times(AtLeast(1))
        .WillRepeatedly(Return(false));

    // Act
    int response = db.Init("krishna", "lagad");

    // Assert
    EXPECT_EQ(response, -1);
}

#endif // UNITTESTS_HPP
