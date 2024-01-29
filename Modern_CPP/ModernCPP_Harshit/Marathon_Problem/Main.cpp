#include <iostream>
#include "Functionalities.h"

int main() {
    Container data;
    createObjects(data);
    std::string id = "CAR2024-103";
    std::cout << "Horsepower of car is: " << getHPByCarId(id, data) << std::endl;
    return 0;
}