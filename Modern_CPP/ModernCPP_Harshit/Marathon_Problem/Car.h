#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include "Engine.h"
#include "CarType.h"

class Car {
    private:
        static int _counter;
        std::string _carId {"XXXXXX"};
        std::string _carBrand {"AAAAAA"};
        CarType _carType {CarType::SUV};
        Engine& _carEngine;
        float _carPrice {0.0f};

    public:
        Car() = default;
        // ~Car() { std::cout << "Car destroyed!! " << _carId << std::endl; };
        ~Car() {};

        Car(std::string, CarType, Engine&, float);

        std::string getCarId() const { return _carId; }
        void setCarId(const std::string &carId_) { _carId = carId_; }

        std::string getCarBrand() const { return _carBrand; }
        void setCarBrand(const std::string &carBrand_) { _carBrand = carBrand_; }

        CarType getCarType() const { return _carType; }
        void setCarType(const CarType &carType_) { _carType = carType_; }

        Engine& getCarEngine() const { return _carEngine; }
        void setCarEngine(const Engine& carEngine_) { _carEngine = carEngine_; }

        float getCarPrice() const { return _carPrice; }
        void setCarPrice(float carPrice_) { _carPrice = carPrice_; }
};

inline int Car::_counter = 100;

#endif // CAR_H
