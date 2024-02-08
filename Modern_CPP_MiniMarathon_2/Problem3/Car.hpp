#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "CarType.hpp"

class Car {
    private:
        float _carPrice;
        std::string _carModel;
        CarType _carType;
        int _carSeatCount;

    public:
        Car() = delete;
        Car(const Car&) = delete;
        Car(Car&&) = delete;
        Car& operator=(const Car&) = delete;
        Car& operator=(Car&&) = delete;
        ~Car() {}

        Car(float price, std::string model, CarType type, int seats);

        float carPrice() const { return _carPrice; }
        void setCarPrice(float carPrice) { _carPrice = carPrice; }

        std::string carModel() const { return _carModel; }
        void setCarModel(const std::string &carModel) { _carModel = carModel; }

        CarType carType() const { return _carType; }
        void setCarType(const CarType &carType) { _carType = carType; }

        int carSeatCount() const { return _carSeatCount; }
        void setCarSeatCount(int carSeatCount) { _carSeatCount = carSeatCount; }

        virtual float calculateInsuranceCost() = 0;

        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);

        
};

#endif // CAR_HPP
