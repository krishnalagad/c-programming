#include <iostream>
#include "Car.h"

// constructor delegation here...
Car::Car(std::string id): _id(id), _price(0.0f), _type(VehicleType::SEDAN) {}

Car::Car(std::string id, VehicleType type): Car(id) {
    _price = 0.0f;
    _type = type;
}

Car::Car(std::string id, float price, VehicleType type)
: Car(id, type) {
    _price = price;
}

