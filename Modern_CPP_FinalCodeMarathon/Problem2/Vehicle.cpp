#include "Vehicle.hpp"

std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_vehicleId: " << rhs._vehicleId
       << " _activeDurationMonths: " << rhs._activeDurationMonths
       << " _latestServiceRecord: " << rhs._latestServiceRecord;
    return os;
}

Vehicle::Vehicle(std::string id, int duration, ServiceRecordRef record)
    : _vehicleId(id), _activeDurationMonths(duration), _latestServiceRecord(record) {}
