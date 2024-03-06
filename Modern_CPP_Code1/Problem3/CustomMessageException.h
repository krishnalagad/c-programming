#ifndef CUSTOMMESSAGEEXCEPTION_H
#define CUSTOMMESSAGEEXCEPTION_H

#include <string>

class CustomMessageException {
    private:
        std::string _message;
    public:
        CustomMessageException(std::string message): _message(message) {}
        CustomMessageException() = delete;
        ~CustomMessageException() {}
        std::string what() { return _message; }
};

#endif // CUSTOMMESSAGEEXCEPTION_H
