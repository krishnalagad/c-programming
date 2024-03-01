#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include "Car.h"
#include <memory>

using Pointer = std::shared_ptr<Car>;       // create smart pointer of class Car using shared_ptr
using container = std::vector<Pointer>;     // using keyword is alternative for typedef

/* 
    takes one parameter of type lvalue reference of container whereas container is vector 
    of Pointer and Pointer is a shared pointer of Car and returns void. 
*/
void createObjects(container& data); 
float averagePrice(container& data);
float getPriceById(container& data, std::string id);

float getAvg(std::vector<Car*> v);
Car& getCarById(std::vector<Car*> v, std::string id);

#endif // FUNCTIONALITIES_H
