#include "Car.hpp"

Car::Car(float price, std::string model, CarType type, int seats)
    : _carPrice(price), _carModel(model), _carType(type), _carSeatCount(seats) {}

    
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_carPrice: " << rhs._carPrice
       << " _carModel: " << rhs._carModel
       << " _carType: " << static_cast<int> (rhs._carType)
       << " _carSeatCount: " << rhs._carSeatCount;
    return os;
}
