#include "ICEngineCar.hpp"


std::ostream &operator<<(std::ostream &os, const ICEngineCar &rhs) {
    os << "_fuelCapacity: " << rhs._fuelCapacity
       << " _fuelType: " << static_cast<int> (rhs._fuelType);
    return os;
}
ICEngineCar::ICEngineCar(float price, std::string model, CarType type, int seats, float fuel, FuelType ftype)
    : Car(price, model, type, seats), _fuelCapacity(fuel), _fuelType(ftype) {}

float ICEngineCar::calculateInsuranceCost() {
    if (fuelType() == FuelType::PETROL)
        return 1000 * fuelCapacity();
    if (fuelType() == FuelType::DIESEL)
        return 1500 * fuelCapacity();
    
    return 12 * fuelCapacity();
}

float ICEngineCar::calculateServicingCost() {
    if (FuelType::PETROL == fuelType())
        return 100 * fuelCapacity();
    if (FuelType::DIESEL == fuelType())
        return 150 * fuelCapacity();
    if (FuelType::CNG == fuelType()) {
        if (carSeatCount() < 6)
            return 100 * fuelCapacity();
        if (carSeatCount() > 5)
            return 120 * fuelCapacity();
    }
    return 0.0f;
}
