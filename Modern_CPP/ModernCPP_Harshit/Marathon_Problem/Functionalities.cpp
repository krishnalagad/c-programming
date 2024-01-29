#include <algorithm>
#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

void createObjects(Container& data) {
    Engine supraEngine = Engine(EngineType::HYBRID, 900, 660);
    Engine mustangEngine = Engine(EngineType::HYBRID, 850, 630);
    Engine gtrEngine = Engine(EngineType::HYBRID, 1020, 720);
    data.push_back(
        std::make_shared<Car>(
            "Toyota Supra",
            CarType::SPORTS,
            supraEngine,
            80000.0f
        )
    );
    data.push_back(
        std::make_shared<Car>(
            "Ford Mustang",
            CarType::SPORTS,
            mustangEngine,
            80000.0f
        )
    );
    data.push_back(
        std::make_shared<Car>(
            "Nissan GTR",
            CarType::SPORTS,
            gtrEngine,
            80000.0f
        )
    );
}

int getHPByCarId(std::string carId, Container& data) {
    std::cout << "Car ID: " << carId << std::endl;
    auto it = std::find_if(std::begin(data), std::end(data), [carId](const CarPointer& car){
        return carId == car->getCarId();
    });
    if (it !=std::end(data)) {
        CarPointer c = *it;
        return c->getCarEngine().engineHorsepower();
    } else {
        throw CarNotExistsException("Car doesn't exist with ID " + carId + "\n");
    }
}

// int getHPByCarId(std::string carId) {
//     std::cout << "Car ID: " << carId << std::endl;
//     // auto it = std::find_if(std::begin(data), std::end(data), [carId](const CarPointer& car){
//     //     return carId == car->getCarId();
//     // });
//     // if (it !=std::end(data)) {
//     //     CarPointer c = *it;
//     //     return c->getCarEngine().engineHorsepower();
//     // } else {
//     //     throw CarNotExistsException("Car doesn't exist with ID " + carId + "\n");
//     // }
//     return 0;
// }