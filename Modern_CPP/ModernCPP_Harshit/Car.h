#ifndef CAR_H
#define CAR_H

#include <string>
#include "CarType.h"

class Car {
    private:
        std::string _id;
        float _price;
        VehicleType _type;

    public:
        // Six special functions
        Car() = delete;     // deleted default constructor, means dont want default constructor
        Car(const Car&) = delete;  // deleted copy constructor
        ~Car() = default;   // defaulted desctructor
        Car& operator=(const Car&) = delete;
        Car& operator=(const Car&&) = delete;   // new concept! move assignment
        Car(Car&&) = delete;    // new concept! move constructor
};

#endif // CAR_H
