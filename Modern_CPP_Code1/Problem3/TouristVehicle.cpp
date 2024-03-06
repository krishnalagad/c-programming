#include "TouristVehicle.h"

#include <iostream>

TouristVehicle::TouristVehicle(TouristVehicleType type, int seatCount, float perHourCharges, PermitPointer permit)
    : _number("MH12Cm" + std::to_string(++_counter)), _type(type), _seat_count(seatCount),
    _per_hour_booking_charge(perHourCharges), _permit(permit) {}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _type: " << static_cast<int> (rhs._type)
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " \n_permit details: \n SerialNumber: " << rhs._permit->serialNumber()
       << " \nDuration Left: " << rhs._permit->permitDurationLeft();
       os << "\n";
    return os;
}
