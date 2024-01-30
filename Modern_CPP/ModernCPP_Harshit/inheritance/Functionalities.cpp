#include "Functionalities.h"

void createObjects(DataContainer &data) {
    data.emplace_back(std::make_shared<Car>(CarType::SEDAN, "V101", 89000.0f, VehicleType::COMMERCIAL));
    data.emplace_back(std::make_shared<Car>(CarType::SUV, "V102", 99000.0f, VehicleType::COMMERCIAL));
    data.emplace_back(std::make_shared<Car>(CarType::SEDAN, "V103", 79000.0f, VehicleType::COMMERCIAL));
}

float calculateTotalRegistrationTax(const DataContainer &data) {
    if (data.empty())
        throw std::runtime_error("Enpty data received!!");
    float total = 0.0f;
    for (const VehiclePointer& car: data) 
        total += car->calculateRegistrationTax();
    
    return total;
}