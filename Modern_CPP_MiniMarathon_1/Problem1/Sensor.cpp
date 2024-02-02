#include "Sensor.h"
#include "SensorType.h"
#include <iostream>

Sensor::Sensor(std::string name, SensorType type, int reading)
    : _sensorId(++_counter), _sensorName(name), _sensorType(type), _sensorReading(reading) {}


std::ostream &operator<<(std::ostream &os, const Sensor &rhs) {
    os << "_sensorId: " << rhs._sensorId << std::endl
       << " _sensorName: " << rhs._sensorName << std::endl
       << " _sensorReading: " << rhs._sensorReading << std::endl;
       switch (rhs._sensorType){
        case SensorType::CABIN_PRESSURE:
            std::cout << "SensorType: CABIN_PRESSURE\n";
            break;
        case SensorType::TEMPERATURE:
        std::cout << "SensorType: TEMPERATURE\n";
            break;
        case SensorType::TYRE_PRESSURE:
        std::cout << "SensorType: TYRE_PRESSURE\n";
            break;
        
        default:
            break;
       }
    os << "\n";
    return os;
}
