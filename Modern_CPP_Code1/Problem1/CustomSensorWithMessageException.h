#ifndef CUSTOMSENSORWITHMESSAGEEXCEPTION_H
#define CUSTOMSENSORWITHMESSAGEEXCEPTION_H

#include <iostream>

class CustomSensorWithMessageException: public std::exception {
    private:
        std::string _message;
    public:
        CustomSensorWithMessageException() = delete;
        explicit CustomSensorWithMessageException(std::string message): _message(message) {}
        CustomSensorWithMessageException(const CustomSensorWithMessageException&) = default;
        ~CustomSensorWithMessageException() = default;
        std::string what() { return _message; }
};

#endif // CUSTOMSENSORWITHMESSAGEEXCEPTION_H
