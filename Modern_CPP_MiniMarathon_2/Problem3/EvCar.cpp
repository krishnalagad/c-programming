#include "EvCar.hpp"
#include "CarType.hpp"

EvCar::EvCar(float price, std::string model, CarType type, int seats, float battery)
    : Car(price, model, type, seats), _batteryCapacity(battery) {}

float EvCar::calculateInsuranceCost() {
    if (carType() == CarType::PRIVATE_CAR) 
        return 0.2 * carPrice();
    return 0.1 * carPrice();
}

float EvCar::calculateFastChargingCost() {
    return 0.0f;
}

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << static_cast<const Car &>(rhs)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    return os;
}
