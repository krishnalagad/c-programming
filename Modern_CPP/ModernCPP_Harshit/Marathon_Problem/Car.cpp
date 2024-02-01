#include <string>
#include <iostream>
#include "Car.h"

// Car::Car(std::string carBrand, CarType carType, Engine& carEngine, float carPrice)
//     : _carId("CAR2024-" + std::to_string(++_counter)), _carBrand(carBrand), _carType(carType), _carEngine(carEngine), 
//     _carPrice(carPrice) {}

Car::Car(std::string id, std::string brand, CarType carType, RefType ref, float price)
    : _carId(id), _carBrand(brand), _carType(carType),  {}

std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_carId: " << rhs._carId
       << " _carBrand: " << rhs._carBrand
       << " _carType: " << static_cast<int>(rhs._carType)
       << " _carEngine: " << rhs._carEngine.get()
       << " _carPrice: " << rhs._carPrice;
    return os;
}
