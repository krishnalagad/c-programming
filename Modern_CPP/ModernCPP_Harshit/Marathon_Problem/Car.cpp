#include <string>
#include <iostream>
#include "Car.h"

Car::Car(std::string carBrand, CarType carType, Engine& carEngine, float carPrice)
    : _carId("CAR2024-" + std::to_string(++_counter)), _carBrand(carBrand), _carType(carType), _carEngine(carEngine), 
    _carPrice(carPrice) {}