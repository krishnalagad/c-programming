#include <algorithm>
#include <vector>
#include <iostream>
#include "Car.h"
#include "Functionalities.h"
#include <algorithm>

void createObjects(container &data) {
    data.push_back(std::make_shared<Car>("car001", 23000.3f, VehicleType::HATCHBACK));
    data.push_back(std::make_shared<Car>("car002", 83000.3f, VehicleType::SUV));
    Pointer p1 = std::make_shared<Car>("car003", 53000.3f, VehicleType::SEDAN);
    data.push_back(p1);
}

float averagePrice(container &data) {
    float sum;
    for(Pointer& p: data) 
        sum += p->price();
    
    return sum / data.size();
}

float getPriceById(container &data, std::string id) {
    float tot;
    for(Pointer& ptr: data)
        if (id == ptr->id())
            return ptr->price();
    throw std::runtime_error("NO ID FOUND!!");
}

float getAvg(std::vector<Car *> v) {
    float sum;
    for(Car* c: v) {
        float price = c->price();
        sum += price;
    }
    return sum / v.size();
}

Car& getCarById(std::vector<Car*> v, std::string id) {
    // if (v.size()<= 0)
    //     return;

    auto it = std::find_if(v.begin(), v.end(), [&id](const Car* carPtr) {
        return id == carPtr->id();
    });

    if (!(it == std::end(v))) {
        return **it;
    }
}