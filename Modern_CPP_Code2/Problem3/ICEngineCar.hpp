#ifndef ICENGINECAR_HPP
#define ICENGINECAR_HPP

#include "FuelType.hpp"
#include "Car.hpp"
#include <string>
#include <ostream>

class ICEngineCar: public Car {
private:
    float _fuelCapacity;
    FuelType _fuelType;

public:
    ICEngineCar() = delete;
    ICEngineCar(const ICEngineCar&) = delete;
    ICEngineCar(ICEngineCar&&) = delete;
    ICEngineCar& operator=(const ICEngineCar&) = delete;
    ICEngineCar& operator=(ICEngineCar&&) = delete;
    ~ICEngineCar() {}

    ICEngineCar(float price, std::string model, CarType type, int seats, float fuel, FuelType ftype);

    float fuelCapacity() const { return _fuelCapacity; }
    void setFuelCapacity(float fuelCapacity) { _fuelCapacity = fuelCapacity; }

    FuelType fuelType() const { return _fuelType; }
    void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }

    friend std::ostream &operator<<(std::ostream &os, const ICEngineCar &rhs);

    float calculateInsuranceCost() override;
    float calculateServicingCost();
};

#endif // ICENGINECAR_HPP
