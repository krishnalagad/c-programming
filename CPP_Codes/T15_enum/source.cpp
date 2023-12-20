#include <iostream>
#include "user.h"

User::User(int userId, std::string userName) : id(userId), name(userName), currentActivity(READING) {}

void User::display() {
    std::cout << "User ID: " << id << "\nName: " << name << "\nHobbie: ";
    switch (currentActivity) {
        case READING:
            std::cout << "Reading";
            break;
        case WRITING:
            std::cout << "Writing";
            break;
        case TRAVELLING:
            std::cout << "Travelling";
            break;
    }
    std::cout << "\n\n";
}