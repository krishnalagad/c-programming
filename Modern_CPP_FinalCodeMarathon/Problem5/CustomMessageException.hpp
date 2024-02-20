#ifndef CUSTOMMESSAGEEXCEPTION_HPP
#define CUSTOMMESSAGEEXCEPTION_HPP

#include <iostream>

class CustomMessageException {
    private:
        std::string _message;
        
    public:
        CustomMessageException() = delete;
        CustomMessageException(std::string message): _message(message) {}
        ~CustomMessageException() = default;
        std::string what() { return _message; }
};

#endif // CUSTOMMESSAGEEXCEPTION_HPP
