#include "Functionalities.h"
#include "CustomSensorWithMessageException.h"

/*
    takes lvalue ref of vector of SensorPointer returns void
*/
void creteObjects(SensorPointerListContainer &data){
    data.push_back(
        std::make_shared<Sensor>(
            "Sensor 1",
            SensorType::CABIN_PRESSURE,
            34));

    data.push_back(
        std::make_shared<Sensor>(
            "Sensor 2",
            SensorType::TEMPERATURE,
            45));

    data.push_back(
        std::make_shared<Sensor>(
            "Sensor 2",
            SensorType::TEMPERATURE,
            23));
}

/*
    takes constant lvalue ref of vector of SensorPointer returns bool
*/
bool isSensorsAbove25ReadingExists(const SensorPointerListContainer &data, int inputReadingValue) {
    if (data.empty()) 
        throw CustomSensorWithMessageException("SensorPointerListContainer is empty!!");

    for (const SensorPointer& ptr: data ) {
        if (ptr->sensorReading() > inputReadingValue) 
            return true;
    }
    return false;
}

/*
    takes constant lvalue ref of vector of SensorPointer returns float
*/
float getAverageReadingValueOfSensors(const SensorPointerListContainer& data, SensorType inputSensorType) {
    if (data.empty()) 
        throw CustomSensorWithMessageException("SensorPointerListContainer is empty!!");

    float total = 0.0f;
    int count = 0;
    for (const SensorPointer& ptr: data) {
        if (inputSensorType == ptr->sensorType()) {
            total += ptr->sensorReading();
            count += 1;
        }
    }

    return total / count;
}

/*
    takes constant lvalue ref of vector of SensorPointer returns container of SensorPointer by value
*/
SensorPointerListContainer getSensorsWithReadingAbove15AndTypeTyre(const SensorPointerListContainer &data) {
    if (data.empty()) 
        throw CustomSensorWithMessageException("SensorPointerListContainer is empty!!");

    SensorPointerListContainer result;
    for (const SensorPointer& ptr: data) {
        if ((ptr->sensorReading() > 15) && (ptr->sensorType() == SensorType::TEMPERATURE)) {
            result.push_back(ptr);
        }
    }

    return result;
}

