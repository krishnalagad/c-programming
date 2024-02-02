#ifndef INSTANCEBEYONDEXCEPTION_H
#define INSTANCEBEYONDEXCEPTION_H

#include <string>

class InstanceBeyondException {
    private:
        std::string _message;
    public:
        InstanceBeyondException(std::string message): _message(message) {}
        InstanceBeyondException() = delete;
        ~InstanceBeyondException() {}
        std::string what() { return _message; }
};

#endif // INSTANCEBEYONDEXCEPTION_H
