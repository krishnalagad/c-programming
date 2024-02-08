#ifndef EVEvCar_HPP
#define EVEvCar_HPP

#include "Car.hpp"
#include <ostream>

class EvCar: public Car {
    private:
        float _batteryCapacity;

    public:
        EvCar() = delete;
        EvCar(const EvCar&) = delete;
        EvCar(EvCar&&) = delete;
        EvCar& operator=(const EvCar&) = delete;
        EvCar& operator=(EvCar&&) = delete;
        ~EvCar() {}

        EvCar(float price, std::string model, CarType type, int seats, float battery);

        float batteryCapacity() const { return _batteryCapacity; }
        void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

        float calculateInsuranceCost() override;
        float calculateFastChargingCost();

        friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);

};

#endif // EVEvCar_HPP
