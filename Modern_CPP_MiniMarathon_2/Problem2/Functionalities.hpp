// Functionalities.hpp

#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Flight.hpp"
#include <functional>
#include <memory>
#include <vector>

using FlightPointer = std::shared_ptr<Flight>;
using FlightPointerContainer = std::vector<FlightPointer>;
using AirplaneContainer = std::vector<Airplane>;

using FnType1 = std::function<AirplaneContainer(FlightPointerContainer&, FlightOperatorType&)>;
using FnType2 = std::function<AirplaneType(AirplaneContainer&)>;
using FnType3 = std::function<AirplaneContainer(AirplaneContainer&, int)>;
using FnType4 = std::function<int(AirplaneContainer&)>;

// Declare lambda functions as global variables
extern FnType1 getAirplanes;
extern FnType2 getPlane;
extern FnType3 getAirplanesWithMatchingThreshold;
extern FnType4 getTotalSeats;

void createInstancesOfFlight(FlightPointerContainer& data, AirplaneContainer& airplanes);
AirplaneContainer getAirplanesWithMatchingOperator(FlightPointerContainer& data, FlightOperatorType type);
void makeLambda();

#endif // FUNCTIONALITIES_HPP
