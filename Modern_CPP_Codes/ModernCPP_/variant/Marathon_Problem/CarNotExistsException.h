#include <cstring>
#include <iostream>

class CarNotExistsException: public std::exception {
    private:
        char* _message;
    public:
        CarNotExistsException() = delete;
        explicit CarNotExistsException(const char* message) { 
            _message = new char[strlen(message) + 1];
            strcpy(_message, message); 
        }
        CarNotExistsException(const CarNotExistsException&) = default;
        CarNotExistsException(CarNotExistsException&&) = default;
        CarNotExistsException& operator=(const CarNotExistsException&) = delete;
        CarNotExistsException& operator=(CarNotExistsException&&) = delete;
        ~CarNotExistsException() { delete []_message; };

        virtual char* what()  { return _message; }
        
};