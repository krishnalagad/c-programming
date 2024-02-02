#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <list>
#include "Sensor.h"

using SensorPointer = std::shared_ptr<Sensor>;      // shared ptr of Sensor
using SensorPointerListContainer = std::list<SensorPointer>;        // list of SensorPointer

void creteObjects(SensorPointerListContainer& data);
bool isSensorsAbove25ReadingExists(const SensorPointerListContainer &data, int inputReadingValue);
float getAverageReadingValueOfSensors(const SensorPointerListContainer& data, SensorType inputSensorType);
SensorPointerListContainer getSensorsWithReadingAbove15AndTypeTyre(const SensorPointerListContainer& data);

#endif // FUNCTIONALITIES_H
