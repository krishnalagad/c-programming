#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

int main() {
    CarPointerContainer data;
    EngineContainer engineData;
    createObjects(data, engineData);
    try {
        std::string id = "C101";
        std::cout << "Horsepower of car is: " << getHPByCarId(id, data) << std::endl;
        getAvgHorsepowerByTypeAndPrice(EngineType::HYBRID, 80000, data);
        std::cout << "Combined price of Cars is " << getCombinedPriceOfTwoCars(data[0], data.at(2)) << std::endl;
        CarPointerContainer result = getCarsByEngineTorque(80, data);
        display(result);
    }
    catch( CarNotExistsException& e) {
        std::cout << e.what();
    }
    

    return 0;
}