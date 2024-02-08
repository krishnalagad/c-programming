#include "Airplane.hpp"

Airplane::Airplane(std::string manufacturer, AirplaneType type, int count)
    : _airplaneManufacturer(manufacturer), __airplaneType(type), _airplaneSeatCount(count) {}

std::ostream &operator<<(std::ostream &os, const Airplane &rhs) {
    os << "_airplaneManufacturer: " << rhs._airplaneManufacturer
       << " __airplaneType: " << static_cast<int>  (rhs.__airplaneType)
       << " _airplaneSeatCount: " << rhs._airplaneSeatCount;
    return os;
}
