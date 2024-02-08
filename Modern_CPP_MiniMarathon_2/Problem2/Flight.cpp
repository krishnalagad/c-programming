#include "Flight.hpp"

Flight::Flight(std::string company, FlightOperatorType type, AirplaneRef ref)
    : _flightCompany(company), _flightType(type), _flightassociatePlane(ref) {}

std::ostream &operator<<(std::ostream &os, const Flight &rhs) {
    os << "_flightCompany: " << rhs._flightCompany
       << " _flightType: " << static_cast<int> (rhs._flightType)
       << " _flightassociatePlane: " << rhs._flightassociatePlane;
    return os;
}
