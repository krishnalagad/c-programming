#include <algorithm>
#include <vector>
#include <iostream>
#include "Car.h"
#include "Functionalities.h"
#include <algorithm>

float getAvg(std::vector<Car*> v) {
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