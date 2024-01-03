#include <iostream>
#include "user.h"
#include "userNotFountException.h"

static int idGenerator = 219300;

User::User(): userId(idGenerator++), username("Default User"), department("QnA") {}

User::User(std::string username, std::string dept): userId(idGenerator++), username(username), department(dept) {}

void User::display() {
    std::cout<<"\nUser ID: "<<this->userId<<"\nUser name: "<<this->username;
    std::cout<<"\nDepartment: "<<this->department;
    std::cout<<"\n";
}

