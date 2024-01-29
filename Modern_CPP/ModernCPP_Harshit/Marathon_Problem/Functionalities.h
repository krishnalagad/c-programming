#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include "Car.h"

using CarPointer = std::shared_ptr<Car>;
using Container  = std::vector<CarPointer>;

void createObjects(Container& data);
int getHPByCarId(std::string carId, Container& data);

void testFun(std::string& str);

#endif // FUNCTIONALITIES_H
