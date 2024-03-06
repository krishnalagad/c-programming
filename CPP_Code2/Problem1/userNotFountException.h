#ifndef USERNOTFOUNTEXCEPTION_H
#define USERNOTFOUNTEXCEPTION_H

#include <iostream>

class UserNotFountException: public std::exception {
    private:
        std::string message;
    public:
        UserNotFountException(): message("User not found!!") {};
        UserNotFountException(std::string message): message(message) {}
        std::string what() { return this->message; }
};

#endif // USERNOTFOUNTEXCEPTION_H
