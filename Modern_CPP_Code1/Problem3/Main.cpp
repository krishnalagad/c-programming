#include "Functionalities.h"
#include "CustomMessageException.h"
#include "InstanceBeyondException.h"

int main() {
    TouristVehiclePointerContainer data;
    createObjects(data);
    try {
        TouristVehiclePointerContainer result = getTouristVehicleInstancesMatchesConsition(data, 4);
        std::cout << "\nRecords that matches with condition: \n\n";
        for (const TouristVehiclePointer& ptr: result)
            std::cout << *ptr <<std::endl;

        std::cout << "0. LEASE\n1. OWNED\n\nEnter Permit Type: ";
        int choice;
        std::cin >> choice;
        float out = getAverageBookingCharge(data, choice);
        std::cout << "\nAverage charges per hours of selected Vehicles: " << out << std::endl;

        std::string str = getSerialNumberOfPermitByMaxCharges(data);
        std::cout << "Permit Serial number with Max booking charge: " << str <<std::endl;

        TouristVehiclePointerContainer output = getFirstNInstances(data, 4);
        std::cout << "\nRecords that matches with condition: \n\n";
        for (const TouristVehiclePointer& ptr: output)
            std::cout << *ptr <<std::endl;

    } catch (CustomMessageException& ex) {
        std::cout << ex.what() << std::endl;
    } catch (InstanceBeyondException& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}