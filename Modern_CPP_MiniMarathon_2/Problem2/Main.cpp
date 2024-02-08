
#include "Functionalities.hpp"
#include <iostream>

/*
    Client code goes here
    - g++ Main.cpp Functionalities.cpp Flight.cpp Airplane.cpp -o app && ./app && rm app
*/
int main() {
    FlightPointerContainer data;
    AirplaneContainer airplanes;

    createInstancesOfFlight(data, airplanes);
    makeLambda();

    AirplaneContainer result = getAirplanes(data, FlightOperatorType::DOMESTIC);
    for (Airplane plane: result) 
        std::cout << plane; 

    AirplaneType p1 =  getPlane(airplanes);
    std::cout << "Type of airplane with lowest seats is: " << static_cast<int> (p1) << std::endl;

    AirplaneContainer res = getAirplanesWithMatchingThreshold(airplanes, 100);
    for (Airplane plane: res) 
        std::cout << plane << std::endl;     // overloaded << operator
    
    int total = getTotalSeats(airplanes);
    std::cout << "Total seats: " << total << std::endl;

    return 0;
}
