#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

#include <iostream>
#include "AirplaneType.hpp"

class Airplane {
private:
    std::string _airplaneManufacturer;
    AirplaneType __airplaneType;
    int _airplaneSeatCount;

public:
    // Special member functions
    Airplane(const Airplane&) = default;
    Airplane(Airplane&&) = delete;
    Airplane& operator=(const Airplane&) = delete;
    Airplane& operator=(Airplane&&) = delete;
    ~Airplane() {}

    // Custom parameterized constructor
    Airplane(std::string manufacturer, AirplaneType type, int count);

    // Getters and setters
    std::string airplaneManufacturer() const { return _airplaneManufacturer; }
    void setAirplaneManufacturer(const std::string &airplaneManufacturer) { _airplaneManufacturer = airplaneManufacturer; }

    AirplaneType airplaneType() const { return __airplaneType; }
    void setAirplaneType(const AirplaneType &airplaneType) { __airplaneType = airplaneType; }

    int airplaneSeatCount() const { return _airplaneSeatCount; }
    void setAirplaneSeatCount(int airplaneSeatCount) { _airplaneSeatCount = airplaneSeatCount; }

    friend std::ostream &operator<<(std::ostream &os, const Airplane &rhs);
};

#endif // AIRPLANE_HPP
