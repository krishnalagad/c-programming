#include "EvCar.hpp"

std::ostream &operator<<(std::ostream &os, const EvCar &rhs) {
    os << "_id: " << rhs._id
       << " _chassisType: " << static_cast<int> (rhs._chassisType)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    os << "\n";
    return os;
}

EvCar::EvCar(int id, ChassisType type, float battery)
    :_id(id), _chassisType(type), _batteryCapacity(battery) {}
