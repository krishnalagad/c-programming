#ifndef UNITTESTS_HPP
#define UNITTESTS_HPP

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>

#include "MockDB.hpp"
#include "MyDatabase.hpp"
#include "Fixture.hpp"

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

TEST_F(Fixture, UserExistsWithId) {
    // Arrange
    int searchId = 101;

    // Act and Assert
    auto itr = std::find_if(users.begin(), users.end(), [&](const UserPtr& ptr){
        EXPECT_EQ(searchId, ptr->getId());
        return searchId == ptr->getId();
    });
}

TEST_F(Fixture, UserExistsWithName) {
    // Arrange
    std::string searchName = "Krishna Lagad";

    // Act and Assert
    auto itr = std::find_if(users.begin(), users.end(), [&](const UserPtr& ptr){
        EXPECT_EQ(searchName, ptr->getName());
        return searchName == ptr->getName();
    });
}

#endif // UNITTESTS_HPP
