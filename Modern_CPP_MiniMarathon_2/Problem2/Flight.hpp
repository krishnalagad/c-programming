#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <string>
#include <functional>
#include <ostream>
#include "FlightOperatorType.hpp"
#include "Airplane.hpp"

using AirplaneRef = std::reference_wrapper<Airplane>;

class Flight {
private:
    std::string _flightCompany;
    FlightOperatorType _flightType;
    AirplaneRef _flightassociatePlane;

public:
    // Special member functions
    Flight(const Flight&) = delete;
    Flight(Flight&&) = delete;
    Flight& operator=(const Flight&) = delete;
    Flight& operator=(Flight&&) = delete;
    ~Flight() {}

    // Custom parameterized constructor
    Flight(std::string company, FlightOperatorType type, AirplaneRef ref);

    // Getters and setters
    std::string flightCompany() const { return _flightCompany; }
    void setFlightCompany(const std::string &flightCompany) { _flightCompany = flightCompany; }

    FlightOperatorType flightType() const { return _flightType; }
    void setFlightType(const FlightOperatorType &flightType) { _flightType = flightType; }

    AirplaneRef flightassociatePlane() const { return _flightassociatePlane; }
    void setFlightassociatePlane(const AirplaneRef &flightassociatePlane) { _flightassociatePlane = flightassociatePlane; }

    friend std::ostream &operator<<(std::ostream &os, const Flight &rhs);
};

#endif // FLIGHT_HPP
