#ifndef CAR_H
#define CAR_H

/*
    A car cannot be copied or moved, default instanciation is not allowed.
    This class inherits (extends) Vehicle type. As such, it implements all base class abstract function
*/

#include <string>
#include <ostream>
#include "CarType.h"
#include "Vehicle.h"
#include "VehicleType.h"

class Car: public Vehicle {
    private:
        const CarType _carType;
    public:
        Car() = delete;
        Car(const Car&) = delete;
        Car(Car&&) = delete;
        Car& operator=(const Car&) = delete;
        Car& operator=( Car&&) = delete;
        ~Car() = default;

        // option1: only give ID
        Car(CarType cType, std::string id);
        // option2: ID, Type
        Car(CarType cType, std::string id, VehicleType type);
        // option3: Eveything
        Car(CarType cType, std::string id, float price, VehicleType type);

        CarType carType() const { return _carType; }

        void bookServiceAppointment() override;
        float calculateRegistrationTax() override;

        friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
