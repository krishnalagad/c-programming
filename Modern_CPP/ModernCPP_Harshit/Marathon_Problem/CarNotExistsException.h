#include <cstring>

class CarNotExistsException: public std::exception {
    private:
        char* _message;
    public:
        CarNotExistsException() = delete;
        explicit CarNotExistsException(const char* message) { strcpy(_message, message); }
        CarNotExistsException(const CarNotExistsException&) = default;
        CarNotExistsException(CarNotExistsException&&) = delete;
        CarNotExistsException& operator=(const CarNotExistsException&) = delete;
        CarNotExistsException& operator=(CarNotExistsException&&) = delete;
        ~CarNotExistsException() = default;

        virtual const char* what() { return this->_message; }
        
};