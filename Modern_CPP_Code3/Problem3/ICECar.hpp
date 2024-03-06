#ifndef ICECAR_HPP
#define ICECAR_HPP

#include <iostream>
#include "FuelType.hpp"

class ICECar {
    private:
        const int _id;
        FuelType _fuelType;
        unsigned int _fuelTankCapacity;
        
    public:
        ICECar() = delete;
        ICECar(const ICECar&) = default;
        ICECar(ICECar&&) = default;
        ICECar& operator=(const ICECar&) = default;
        ICECar& operator=(ICECar&&) = default;
        ~ICECar() = default;

        ICECar(int id, FuelType type, unsigned int capacity);

        FuelType fuelType() const { return _fuelType; }
        void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }

        unsigned int fuelTankCapacity() const { return _fuelTankCapacity; }
        void setFuelTankCapacity(unsigned int fuelTankCapacity) { _fuelTankCapacity = fuelTankCapacity; }

        int id() const { return _id; }

        friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};

#endif // ICECAR_HPP
