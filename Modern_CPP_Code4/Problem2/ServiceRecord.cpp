#include "ServiceRecord.hpp"

std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs) {
    os << "_serviceId: " << rhs._serviceId
       << " _type: " << static_cast<int> (rhs._type)
       << " _durationHours: " << rhs._durationHours
       << " _charges: " << rhs._charges
       << " _serviceAttendantName: " << rhs._serviceAttendantName
       << " _serviceLocation: " << rhs._serviceLocation;
    os << "\n";
    return os;
}

ServiceRecord::ServiceRecord(std::string id, ServiceType type, int hours, float charges, std::string name, std::string location)
    : _serviceId(id), _type(type), _durationHours(hours), _charges(charges), 
        _serviceAttendantName(name), _serviceLocation(location) {}
