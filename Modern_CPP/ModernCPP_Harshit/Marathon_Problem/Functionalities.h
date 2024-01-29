#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <string>
#include <vector>
#include "Car.h"

using CarPointer = std::shared_ptr<Car>;
using Container  = std::vector<CarPointer>;

void createObjects(Container& data);

#endif // FUNCTIONALITIES_H
