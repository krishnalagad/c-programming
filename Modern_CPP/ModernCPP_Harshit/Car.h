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
        Car() = default;     // deleted default constructor, means dont want default constructor
        // Car(const Car&) = delete;  // deleted copy constructor
        ~Car() = default;   // defaulted desctructor
        // Car& operator=(const Car&) = delete;
        // Car& operator=(const Car&&) = delete;   // new concept! move assignment
        // Car(Car&&) = delete;    // new concept! move constructor

        Car(std::string, float, VehicleType);

        std::string id() const { return _id; }
        void setId(const std::string &id) { _id = id; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        VehicleType type() const { return _type; }
        void setType(const VehicleType &type) { _type = type; }
};

#endif // CAR_H
