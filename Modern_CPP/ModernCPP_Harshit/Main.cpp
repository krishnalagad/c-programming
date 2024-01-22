#include <iostream>
#include "Car.h"
#include "CarType.h"
#include <algorithm>
#include <vector>
#include "Functionalities.h"

int main() {
    std::vector<Car*> v = { new Car("car001", 23000.3, VehicleType::HATCHBACK), 
                            new Car("car002", 32000.3, VehicleType::SEDAN),
                            new Car("car003", 56000.3, VehicleType::SUV) };

    std::cout<<"Average price of 3 Cars is: "<<getAvg(v)<<std::endl;
    // std::cout
    std::string id = "car001";
    Car resultCar = getCarById(v, id);

    std::cout<<"ID: "<<resultCar.id()<<std::endl;
    std::cout<<"Price: "<<resultCar.price()<<std::endl;


    container data;    // empty container

    createObjects(data);

    averagePrice(data);

    getPriceById(data, id);

    return 0;
}   