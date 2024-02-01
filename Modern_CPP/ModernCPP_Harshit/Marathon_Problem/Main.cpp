#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

int main() {
    CarPointerContainer data;
    createObjects(data);
    try {
        std::string id = "CAR2024-101";
        std::cout << "Horsepower of car is: " << getHPByCarId(id, data) << std::endl;
        getAvgHorsepowerByTypeAndPrice(EngineType::HYBRID, 80000, data);
        std::cout << "Combined price of Cars is " << getCombinedPriceOfTwoCars(data[0], data.at(2)) << std::endl;
    }
    catch(CarNotExistsException& e) {
        std::cout << e.what();
    }
    CarPointerContainer result = getCarsByEngineTorque(80, data);
    display(result);

    return 0;
}