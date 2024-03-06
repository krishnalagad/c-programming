#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <ostream>
#include "SensorType.h"

class Sensor {
    private:
        static int _counter;
        const int _sensorId;    // ID can't be changed once assigned
        std::string _sensorName;
        const SensorType _sensorType;   // sensor type cant be changed, once sensor has created
        int _sensorReading;

    public:
        // Six special function
        Sensor() = delete;
        Sensor(const Sensor&) = delete;
        Sensor(Sensor&&) = delete;
        Sensor& operator=(const Sensor&) = delete;
        Sensor& operator=(Sensor&&) = delete;
        ~Sensor() = default;

        // User defined parameterized constructor
        Sensor(std::string, SensorType, int);

        // getters and setters
        int sensorId() const { return _sensorId; }  

        std::string sensorName() const { return _sensorName; }
        void setSensorName(const std::string &sensorName) { _sensorName = sensorName; }

        SensorType sensorType() const { return _sensorType; }

        int sensorReading() const { return _sensorReading; }
        void setSensorReading(int sensorReading) { _sensorReading = sensorReading; }

        friend std::ostream &operator<<(std::ostream &os, const Sensor &rhs);
};

inline int Sensor::_counter = 100;
#endif // SENSOR_H
