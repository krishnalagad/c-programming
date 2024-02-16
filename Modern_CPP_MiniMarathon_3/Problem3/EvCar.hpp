#ifndef EVCAR_HPP
#define EVCAR_HPP

#include "ChassisType.hpp"
#include <iostream>

class EvCar {
    private:
        const int _id;
        ChassisType _chassisType;
        float _batteryCapacity;

    public:
        EvCar() = delete;
        EvCar(const EvCar&) = default;
        EvCar(EvCar&&) = default;
        EvCar& operator=(const EvCar&) = default;
        EvCar& operator=(EvCar&&) = default;
        ~EvCar() = default;

        EvCar(int id, ChassisType type, float battery);

        int id() const { return _id; }
        
        ChassisType chassisType() const { return _chassisType; }
        void setChassisType(const ChassisType &chassisType) { _chassisType = chassisType; }

        float batteryCapacity() const { return _batteryCapacity; }
        void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

        friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);
};

#endif // EVCAR_HPP
