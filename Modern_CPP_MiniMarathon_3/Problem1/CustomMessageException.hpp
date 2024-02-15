#ifndef CUSTOMMESSAGEEXCEPTION_HPP
#define CUSTOMMESSAGEEXCEPTION_HPP

#include <iostream>

class CustomMessageException: public std::exception {
    private:
        std::string _message;
    public:
        CustomMessageException() = delete;
        CustomMessageException(std::string message): _message(message) {}
        std::string what() { return _message; }
        ~CustomMessageException() {}
};

#endif // CUSTOMMESSAGEEXCEPTION_HPP
