#ifndef FIXTURE_HPP
#define FIXTURE_HPP

#include <vector>
#include <functional>
#include <gtest/gtest.h>
#include <memory>
#include "User.hpp"

using UserPtr = std::shared_ptr<User>;
using UserDB = std::vector<UserPtr>;
struct Fixture: public testing::Test {
    UserDB users;
    void SetUp() override {
        users.push_back(std::make_shared<User>(101, "Krishna Lagad", 23.1f, "+919834808052"));
        users.push_back(std::make_shared<User>(102, "Jack Sparrow", 45.3f, "+918834808053"));
        users.push_back(std::make_shared<User>(103, "Bruse Wayne", 55.5f, "+917834808054"));
        users.push_back(std::make_shared<User>(104, "Tony Stark", 47.7f, "+916834808054"));
    }
    void TearDown() override {}
};


#endif // FIXTURE_HPP
