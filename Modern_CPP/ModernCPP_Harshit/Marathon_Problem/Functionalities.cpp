#include <algorithm>
#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

void createObjects(Container& data) {

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
            90000.0f
        )
    );
    data.push_back(
        std::make_shared<Car>(
            "Nissan GTR",
            CarType::SPORTS,
            gtrEngine,
            180000.0f
        )
    );
}

int getHPByCarId(std::string carId, Container& data) {
    auto it = std::find_if(std::begin(data), std::end(data), [carId](const CarPointer& car){
        return carId == car->getCarId();
    });
    if (it != std::end(data)) {
        CarPointer c = *it;
        if (c) 
            return c->getCarEngine().engineHorsepower();
        else 
            throw CarNotExistsException("Car found with ID " + carId + " but has a null pointer.\n");
    } else 
        throw CarNotExistsException("Car doesn't exist with ID " + carId + "\n");
}

Container getCarsByEngineTorque(int torque, Container& data) {
    Container result;
    for(CarPointer car: data) {
        if (torque >= car->getCarEngine().engineTorque()){
            result.push_back(car);
        }
    }
    return result;
}

void display(const Container& data) {
    for(CarPointer car: data) {
        std::cout << "Car ID: " << car->getCarId() << std::endl;
        std::cout << "Car Brand: " << car->getCarBrand() << std::endl;
        std::cout << "Car Price: " << car->getCarPrice() << std::endl;
        std::cout << "Car Type: " << (int) car->getCarType() << std::endl;

        std::cout << "Engine Number: " << car->getCarEngine().engineNumber() << std::endl;
        std::cout << "Engine Horsepower: " << car->getCarEngine().engineHorsepower() << std::endl;
        std::cout << "Engine Torque: " << car->getCarEngine().engineTorque() << std::endl;
        std::cout << "Engine Type: " << (int) car->getCarEngine().engineType() << std::endl;
    }
}

void getAvgHorsepowerByTypeAndPrice(EngineType engineType, float carPrice, const Container& data) {
    float sumHp = 0.0f;
    int count = 0;
    for (CarPointer car: data) {
        if (car->getCarPrice() > carPrice && car->getCarEngine().engineType() == engineType) {
            sumHp += car->getCarEngine().engineHorsepower();
            count += 1;
        }
    }
    if (count) {
        float avg = sumHp / count;
        std::cout << "Average of horsepower is " << avg <<std::endl;
    } else 
        throw CarNotExistsException("Car not found!!");
}

float getCombinedPriceOfTwoCars(CarPointer& c1, CarPointer& c2) {
    
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

void testFun(std::string& str) {
    std::cout << str <<std::endl;
}