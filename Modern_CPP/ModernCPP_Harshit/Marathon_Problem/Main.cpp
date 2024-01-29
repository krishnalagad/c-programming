#include <iostream>
#include "Functionalities.h"

int main() {
    Container data;
    createObjects(data);
    std::cout << "Horsepower of car is: " << getHPByCarId("CAR2024-103", data) << std::endl;
    return 0;
}