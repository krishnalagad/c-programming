#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <iostream>
#include <vector>
#include "Car.h"

using VehiclePointer = std::shared_ptr<Vehicle>;
using DataContainer = std::vector<VehiclePointer>;

void createObjects(DataContainer& data);
float calculateTotalRegistrationTax(const DataContainer& data);

#endif // FUNCTIONALITIES_H
