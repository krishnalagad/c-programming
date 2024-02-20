#ifndef RECORDNOTFOUNDEXCEPTION_HPP
#define RECORDNOTFOUNDEXCEPTION_HPP

#include <iostream>

class RecordNotFoundException {
    private:
        std::string _message;
        
    public:
        RecordNotFoundException() = delete;
        RecordNotFoundException(std::string message): _message(message) {}
        ~RecordNotFoundException() = default;
        std::string what() { return _message; }
};

#endif // RECORDNOTFOUNDEXCEPTION_HPP
