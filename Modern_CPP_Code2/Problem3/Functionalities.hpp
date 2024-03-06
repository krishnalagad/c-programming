#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

/*
    Declaration of Functionalities for this project goes here in this file
*/

#include "Car.hpp"
#include "CustomMessageException.hpp"
#include "CarType.hpp"
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include "EvCar.hpp"
#include "ICEngineCar.hpp"

using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer = std::vector<CarPointer>;

void createObjects(CarPointerContainer& data);
float carTypeAverageInsuranceCost(const CarPointerContainer& data, CarType type);
std::optional<CarPointerContainer> getInstancesWithConditions(const CarPointerContainer& data);
void display(const CarPointerContainer& data);

#endif // FUNCTIONALITIES_HPP
