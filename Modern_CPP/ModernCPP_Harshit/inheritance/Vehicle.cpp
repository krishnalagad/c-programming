#include "Vehicle.h"

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_vehicleId: " << rhs._vehicleId
       << " _vehiclePrice: " << rhs._vehiclePrice
       << " _vehicleType: " << static_cast<int>(rhs._vehicleType);  // int here is template param
    return os;
}

Vehicle::Vehicle(std::string id): _vehicleId(id) {}

Vehicle::Vehicle(std::string id, VehicleType type): Vehicle(id) { _vehicleType = type; }

Vehicle::Vehicle(std::string id, float price, VehicleType type): Vehicle(id, type) { _vehiclePrice = price; }

float Vehicle::calculateRegistrationTax() {
    return 0.0f;
}
