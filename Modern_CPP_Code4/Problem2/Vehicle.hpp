#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include "ServiceRecord.hpp"
#include <functional>

using ServiceRecordRef = std::reference_wrapper<ServiceRecord>;

class Vehicle {
    private:
        std::string _vehicleId;
        int _activeDurationMonths;
        ServiceRecordRef _latestServiceRecord;
        
    public:
        Vehicle() = delete;
        Vehicle(const Vehicle&) = default;
        Vehicle(Vehicle&&) = default;
        Vehicle& operator=(const Vehicle&) = default;
        Vehicle& operator=(Vehicle&&) = default;
        ~Vehicle() = default;

        // custom parameterized constructor
        Vehicle(std::string id, int duration, ServiceRecordRef record);

        std::string vehicleId() const { return _vehicleId; }

        int activeDurationMonths() const { return _activeDurationMonths; }
        void setActiveDurationMonths(int activeDurationMonths) { _activeDurationMonths = activeDurationMonths; }

        ServiceRecordRef latestServiceRecord() const { return _latestServiceRecord; }
        void setLatestServiceRecord(const ServiceRecordRef &latestServiceRecord) { _latestServiceRecord = latestServiceRecord; }

        friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
  
};

#endif // VEHICLE_HPP
