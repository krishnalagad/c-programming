#include "Car.h"
#include <iostream>

Car::Car(CarType cType, std::string id) : Vehicle(id), _carType(cType) {}

Car::Car(CarType cType, std::string id, VehicleType type): Vehicle(id, type), _carType(cType) {}

Car::Car(CarType cType, std::string id, float price, VehicleType type): Vehicle(id, price, type), _carType(cType) {}

void Car::bookServiceAppointment() { std::cout << "Appointment booked for " << vehicleId() << std::endl; }

/*
    For SEDAN and SUV, tax is 10% and for other categories tax is 15%
*/
float Car::calculateRegistrationTax(){
    if (_carType == CarType::SEDAN || _carType == CarType::SUV)
        return 0.1f * this->vehiclePrice();
    return 0.15f * this->vehiclePrice();
}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << static_cast<const Vehicle &>(rhs)
       << " _carType: " << static_cast<int> (rhs._carType);
    return os;
}
