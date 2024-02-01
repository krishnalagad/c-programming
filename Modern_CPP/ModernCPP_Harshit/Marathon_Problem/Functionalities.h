#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "Car.h"

using CarPointer = std::shared_ptr<Car>;
using CarPointerContainer  = std::vector<CarPointer>;
using EngineContainer = std::vector<Engine>;

// inline Engine supraEngine(EngineType::HYBRID, 900, 66);
// inline Engine mustangEngine(EngineType::HYBRID, 850, 63);
// inline Engine gtrEngine(EngineType::HYBRID, 1020, 92);

void createObjects(CarPointerContainer& data, EngineContainer& engine);
int getHPByCarId(std::string carId, CarPointerContainer& data);
CarPointerContainer getCarsByEngineTorque(int torque, CarPointerContainer& data);
void display(const CarPointerContainer& data);
void getAvgHorsepowerByTypeAndPrice(EngineType engineType, float carPrice, const CarPointerContainer& data);
float getCombinedPriceOfTwoCars(CarPointer c1, CarPointer c2);

void testFun(std::string& str);

#endif // FUNCTIONALITIES_H
