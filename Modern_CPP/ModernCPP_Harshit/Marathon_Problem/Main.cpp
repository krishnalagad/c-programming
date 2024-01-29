#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

int main() {
    Container data;
    createObjects(data);
    try {
        std::string id = "CAR2024-101";
        std::cout << "Horsepower of car is: " << getHPByCarId(id, data) << std::endl;
    }
    catch(CarNotExistsException& e) {
        std::cout << e.what();
    }
    Container result = getCarsByEngineTorque(80, data);
    display(result);
    
    return 0;
}