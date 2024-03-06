#ifndef VEHICLENOTFOUNDEXCEPTION_H
#define VEHICLENOTFOUNDEXCEPTION_H

#include <iostream>

class VehicleNotFoundException: public std::exception {
    private:
        std::string message;
    public:
        VehicleNotFoundException();
        ~VehicleNotFoundException();
        std::string what();
};

VehicleNotFoundException::VehicleNotFoundException(): message("Vehicle not found with given chassis number") {}
VehicleNotFoundException::~VehicleNotFoundException() {}
std::string VehicleNotFoundException::what() { return this->message; }


#endif // VEHICLENOTFOUNDEXCEPTION_H
