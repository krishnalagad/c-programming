#ifndef CAR_H
#define CAR_H

#include <string>
#include "CarType.h"

class Car {
    private:
        std::string _id {"car000"};
        float _price {0.0f};
        VehicleType _type {VehicleType::HATCHBACK};

    public:
        // ---------------- Six special functions---------------
        // Car() = delete;     // deleted default constructor, means dont want default constructor
        Car() = default;    // default : now we can set default values to attr in priavte section
        explicit Car(std::string id);  // mark it explicit, if one param is there
        Car(std::string id, VehicleType type);  // mark it explicit even if one unknown param and other are not
        Car(std::string id, float price, VehicleType type = VehicleType::SEDAN);
        // Car(const Car&) = delete;  // deleted copy constructor
        ~Car() = default;   // defaulted desctructor
        // Car& operator=(const Car&) = delete;
        // Car& operator=(const Car&&) = delete;   // new concept! move assignment
        // Car(Car&&) = delete;    // new concept! move constructor

        std::string id() const { return _id; }
        void setId(const std::string &id) { _id = id; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        VehicleType type() const { return _type; }
        void setType(const VehicleType &type) { _type = type; }
};

#endif // CAR_H
