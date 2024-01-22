#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Car.h"

float getAvg(std::vector<Car*> v);
Car& getCarById(std::vector<Car*> v, std::string id);

#endif // FUNCTIONALITIES_H
