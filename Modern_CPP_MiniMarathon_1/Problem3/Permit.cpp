#include "Permit.h"
#include <iostream>

Permit::Permit(PermitType type, int durationLeft)
    : _serial_number("KRA00PERMIT" + std::to_string(++_counter)), _permit_type(type), 
    _permit_duration_left(durationLeft) {}
    
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serial_number: " << rhs._serial_number
       << " _permit_type: " << static_cast<int> (rhs._permit_type)
       << " _permit_duration_left: " << rhs._permit_duration_left;
    os << "\n";
    return os;
}
