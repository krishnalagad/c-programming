#include <algorithm>
#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

void createObjects(CarPointerContainer& data, EngineContainer& engineData) {

    engineData.emplace_back(
        Engine("E101", EngineType::ICT, 400, 111)
    );
    engineData.emplace_back(
        Engine("E102", EngineType::HYBRID, 500, 161)
    );

    data.emplace_back(
        std::make_shared<Car>(
            "C101",
            "Toyota Supra",
            CarType::SPORTS,
            engineData[1],
            80000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "Ford Mustang",
            CarType::SPORTS,
            engineData[0],
            90000.0f
        )
    );
    data.emplace_back(
        std::make_shared<Car>(
            "Nissan GTR",
            CarType::SPORTS,
            engineData[1],
            180000.0f
        )
    );
}

int getHPByCarId(std::string carId, CarPointerContainer& data) {
    if (data.empty())
        throw CarNotExistsException("Car container is empty!!\n");

    auto it = std::find_if(std::begin(data), std::end(data), [carId](const CarPointer& car){
        return carId == car->getCarId();
    });
    
    if (it != std::end(data)) {
        CarPointer c = *it;
        if (c) 
            return c->carEngine().get().engineHorsepower();
        else 
            throw CarNotExistsException("Car found with ID " + carId + " but has a empty data.\n");
    } else 
        throw CarNotExistsException("Car doesn't exist with ID " + carId + "\n");
}

CarPointerContainer getCarsByEngineTorque(int torque, CarPointerContainer& data) {
    CarPointerContainer result;
    for(CarPointer car: data) {
        if (torque >= car->carEngine().get().engineTorque()){
            result.emplace_back(car);
        }
    }
    return result;
}

void display(const CarPointerContainer& data) {
    std::cout << std::endl;
    for(CarPointer car: data) {
        std::cout << "Car ID: " << car->getCarId() << std::endl;
        std::cout << "Car Brand: " << car->getCarBrand() << std::endl;
        std::cout << "Car Price: " << car->getCarPrice() << std::endl;
        std::cout << "Car Type: " << (int) car->getCarType() << std::endl;

        std::cout << "Engine Number: " << car->getCarEngine().engineNumber() << std::endl;
        std::cout << "Engine Horsepower: " << car->getCarEngine().engineHorsepower() << std::endl;
        std::cout << "Engine Torque: " << car->getCarEngine().engineTorque() << std::endl;
        std::cout << "Engine Type: " << (int) car->getCarEngine().engineType() << std::endl;
        std::cout << std::endl;
    }
}

void getAvgHorsepowerByTypeAndPrice(EngineType engineType, float carPrice, const CarPointerContainer& data) {
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

float getCombinedPriceOfTwoCars(const CarPointer c1, const CarPointer c2) {
    return c1->getCarPrice() + c2->getCarPrice();
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