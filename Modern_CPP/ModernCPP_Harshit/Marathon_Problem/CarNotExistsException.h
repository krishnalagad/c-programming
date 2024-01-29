#include <iostream>

class CarNotExistsException: public std::exception {
    private:
        std::string _message;
    public:
        CarNotExistsException(std::string message): _message(message) {}
        CarNotExistsException(): _message("Car not found!!") {}
        std::string what() { return this->_message; }
        ~CarNotExistsException() {}
};