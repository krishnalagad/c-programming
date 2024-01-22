#include <iostream>
#include "Car.h"

Car::Car(std::string id, float price, VehicleType type)
: _id(id), _price(price), _type(type) {}