#include "Functionalities.hpp"
#include "CustomMessageException.hpp"
#include <iostream>

/*
    Implementation of all the functionalities of this project goes here in this file
*/

/*
    This function takes lvalue reference of FlightPointerContainer, AirplaneContainer where 
    FlightPointerContainer is vector of FlightPointer, FlightPointer is smart pointer of 
    Flight class and AirplaneContainer is vector of Airplanes and returns void
*/

void createInstancesOfFlight(FlightPointerContainer &data, AirplaneContainer &airplanes) {

    // add objects of airplanes
    Airplane a1("Adani Enterprices", AirplaneType::CRUISELINER, 120);
    Airplane a2("TATA", AirplaneType::NEO, 100);
    airplanes.push_back(a1);
    airplanes.push_back(a2);

    // add flight objects
    data.push_back(
        std::make_shared<Flight>(
            "AIR EMIRATES",
            FlightOperatorType::INTERNATIONAL,
            a1));
    data.push_back(
        std::make_shared<Flight>(
            "LUFTANZA",
            FlightOperatorType::INTERNATIONAL,
            a2));
    data.push_back(
        std::make_shared<Flight>(
            "SPACEJET",
            FlightOperatorType::DOMESTIC,
            a1));
    data.push_back(
        std::make_shared<Flight>(
            "AKASA",
            FlightOperatorType::DOMESTIC,
            a2));
            
}


// Define lambda function objects
FnType1 getAirplanes;
FnType2 getPlane;
FnType3 getAirplanesWithMatchingThreshold;
FnType4 getTotalSeats;

// Implementation of lambda functions
void makeLambda() {
    // Implementation of lambda function getAirplanes
    getAirplanes = [](FlightPointerContainer& data, FlightOperatorType type) -> AirplaneContainer {
        if (data.empty())
            throw CustomMessageException("Data container is empty");

        AirplaneContainer result;
        for (const FlightPointer& ptr : data) {
            if (type == ptr->flightType()) {
                Airplane plane = ptr->flightassociatePlane().get();
                std::cout << plane;
                result.push_back(plane);
            }
        }
        return result;
    };


    // Implementation of lambda function getPlane
    getPlane = [](AirplaneContainer& data) -> AirplaneType {
        if (data.empty())
            throw CustomMessageException("Data container is empty");

        auto it = std::min_element(data.begin(), data.end(), [](const Airplane& a1, const Airplane& a2) {
            return a1.airplaneSeatCount() < a2.airplaneSeatCount();
        });

        return it->airplaneType();
    };

    // Implementation of lambda function getAirplanesWithMatchingThreshold
    getAirplanesWithMatchingThreshold = [](AirplaneContainer& data, int threshold) -> AirplaneContainer {
        if (data.empty())
            throw CustomMessageException("Data container is empty");

        AirplaneContainer result;
        for (const auto& plane : data) {
            if (plane.airplaneSeatCount() <= threshold) {
                result.push_back(plane);
            }
        }

        return result;
    };

    // Implementation of lambda function getTotalSeats
    getTotalSeats = [](AirplaneContainer& data) -> int {
        if (data.empty())
            throw CustomMessageException("Data container is empty");

        int total = 0;
        for (const auto& plane : data) {
            total += plane.airplaneSeatCount();
        }

        return total;
    };
}



/*
    This function takes lvalue reference of FlightPointerContainer, FlightOperator where 
    FlightPointerContainer is vector of FlightPointer, FlightPointer is smart pointer of 
    Flight class  and returns optional of AirplaneContainer where AirplaneContainer is vector 
    of Airplanes.
*/
// AirplaneContainer getAirplanesWithMatchingOperator(FlightPointerContainer& data, FlightOperatorType type){
//     AirplaneContainer result =  getAirplanes(data, type);
//     return result;
// }
