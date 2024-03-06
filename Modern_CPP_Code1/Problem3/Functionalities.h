#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <memory>
#include <list>
#include "TouristVehicle.h"
#include "PermitType.h"
#include "TouristVehicleType.h"

using TouristVehiclePointer = std::shared_ptr<TouristVehicle>;
using TouristVehiclePointerContainer = std::list<TouristVehiclePointer>;

void createObjects(TouristVehiclePointerContainer& data);
TouristVehiclePointerContainer getTouristVehicleInstancesMatchesConsition(const TouristVehiclePointerContainer& data, int n);
float getAverageBookingCharge(const TouristVehiclePointerContainer& data, int permitType);
std::string getSerialNumberOfPermitByMaxCharges(const TouristVehiclePointerContainer& data);
TouristVehiclePointerContainer getFirstNInstances(const TouristVehiclePointerContainer& data, int n);

#endif // FUNCTIONALITIES_H
