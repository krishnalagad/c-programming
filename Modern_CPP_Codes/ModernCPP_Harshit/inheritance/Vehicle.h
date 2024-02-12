#ifndef VEHICLE_H
#define VEHICLE_H

/*
    common behaviour
    book an appointment
    pay registration tax
*/

#include <string>
#include <ostream>
#include "VehicleType.h"

class Vehicle {
    private:
        const std::string _vehicleId;
        float _vehiclePrice;
        VehicleType _vehicleType;

    public:
        Vehicle() = delete;
        Vehicle(const Vehicle&) = delete;
        Vehicle(Vehicle&&) = delete;
        Vehicle& operator=(const Vehicle&) = delete;
        Vehicle& operator=( Vehicle&&) = delete;
        ~Vehicle() = default;

        // option1: only give ID
        explicit Vehicle(std::string id);
        // option2: ID, Type
        Vehicle(std::string id, VehicleType type);
        // option3: Eveything
        Vehicle(std::string id, float price, VehicleType type);

        // getters and setters
        std::string vehicleId() const { return _vehicleId; }
        float vehiclePrice() const { return _vehiclePrice; }
        void setVehiclePrice(float vehiclePrice) { _vehiclePrice = vehiclePrice; }
        VehicleType vehicleType() const { return _vehicleType; }
        void setVehicleType(const VehicleType &vehicleType) { _vehicleType = vehicleType; }

        // member functions
        virtual void bookServiceAppointment() = 0;
        virtual float calculateRegistrationTax();
        friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
