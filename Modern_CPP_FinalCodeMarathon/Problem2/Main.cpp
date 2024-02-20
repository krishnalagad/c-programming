#include <iostream>
#include <optional>
#include "Functionalities.hpp"

/*
    Client code:
        g++ -std=c++11 Main.cpp Functionalities.cpp Vehicle.cpp ServiceRecord.cpp -g -o app && time ./app && rm app
*/

int main() {
    VehicleContainer data;
    RecordsContainer records;
    createObjects(data, records);
    std::list<std::string> ids { "VEHICLE001", "VEHICLE002", "VEHICLE003", "VEHICLE004" };

    try {
        std::optional<std::list<Vehicle>> result = getLastInstancesOfVehicles(data, 3);
        if (result.has_value()) {
            std::cout << "\nLast Elements: \n";
            for (const Vehicle& v: result.value()) {
                std::cout << v << std::endl;
            }
        }

        std::map<std::string, std::string> keyVal = getKeyValPairOfIds(data, ids);
        std::cout << "\nKey value Pairs\n";
        for (auto& [k, v]: keyVal) {
            std::cout << "Vehicle Key: " << k << "  " << "Service Key: " << v << std::endl;
        }

        std::cout << "\n";
        std::cout << "Average of charges: " << getAverageCharges(data) << std::endl;

        std::cout << "\nVehicle Id based on ServieRecordId is: " << getVehicleIdByServiceId(data, "SERV003") << std::endl;

    } catch (CustomMessageException& e) {
        std::cerr << e.what() << std::endl;
    } catch (RecordNotFoundException& e) {
        std::cerr << e.what() << std::endl;
    } 

    
    return 0;
}