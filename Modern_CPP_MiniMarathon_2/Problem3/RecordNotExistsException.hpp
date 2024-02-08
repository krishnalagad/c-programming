#ifndef RECORDNOTEXISTSEXCEPTION_HPP
#define RECORDNOTEXISTSEXCEPTION_HPP

#include <iostream>

class RecordNotExistsException : public std::exception {
    private:
        std::string _message;
        
    public:
        RecordNotExistsException() = delete;
        RecordNotExistsException(std::string message): _message(message) {}
        ~RecordNotExistsException() {}
        std::string what() { return _message; }
};

#endif // RECORDNOTEXISTSEXCEPTION_HPP
