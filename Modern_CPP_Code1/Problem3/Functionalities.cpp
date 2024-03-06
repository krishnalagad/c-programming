#include "Functionalities.h"
#include "TouristVehicle.h"
#include "PermitType.h"
#include "TouristVehicleType.h"
#include "CustomMessageException.h"
#include "InstanceBeyondException.h"

#include <algorithm>

/*
    takes lvalue reference of container of TouristVehiclePointer where TouristVehiclePointer is shared ptr
    of TouristVehicle class and returns void
*/
void createObjects(TouristVehiclePointerContainer &data) {
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::BUS, 30, 23,
            std::make_shared<Permit>(
                PermitType::LEASE, 6)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::BUS, 4, 13,
            std::make_shared<Permit>(
                PermitType::LEASE, 12)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::CAB, 4, 34,
            std::make_shared<Permit>(
                PermitType::OWNED, 2)));
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::BIKE, 2, 20,
            std::make_shared<Permit>(
                PermitType::OWNED, 1)));   
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::CAB, 6, 30,
            std::make_shared<Permit>(
                PermitType::LEASE, 1)));   
    data.push_back(
        std::make_shared<TouristVehicle>(
            TouristVehicleType::BIKE, 1, 40,
            std::make_shared<Permit>(
                PermitType::LEASE, 1)));       
}

/*
    takes lvalue reference of container of TouristVehiclePointer, 
    integer number where TouristVehiclePointer is shared ptr
    of TouristVehicle class and returns TouristVehiclePointerContainer by value
*/
TouristVehiclePointerContainer getTouristVehicleInstancesMatchesConsition(const TouristVehiclePointerContainer& data, int n) {
    if (data.empty()) 
        throw CustomMessageException("TouristVehiclePointerContainer is empty!!\n");
    if (data.size() < n)
        throw InstanceBeyondException("Instance index out of bounds exception occured!!");

    TouristVehiclePointerContainer result;
    int count = n;
    for (const TouristVehiclePointer& ptr: data) {
        if (count <= 0) 
            break;
        if (ptr->seatCount()>= 4 && ptr->permit()->permitType() == PermitType::LEASE) {
            result.push_back(ptr);
            count -= 1;
        }
    }
    return result;
}

/*
    takes lvalue reference of container of TouristVehiclePointer, 
    integer number where TouristVehiclePointer is shared ptr
    of TouristVehicle class and returns float number by value
*/
float getAverageBookingCharge(const TouristVehiclePointerContainer &data, int permitType) {
    if (data.empty()) 
        throw CustomMessageException("TouristVehiclePointerContainer is empty!!\n");
    
    float total = 0.0f;
    int count = 0;
    for (const TouristVehiclePointer& ptr: data) {
        if (ptr->permit()->permitType() == static_cast<PermitType>(permitType)) {
            total += ptr->perHourBookingCharge();
            count += 1;
        }
    }
    return total / count;
}

/*
    takes lvalue reference of container of TouristVehiclePointer where TouristVehiclePointer is shared ptr
    of TouristVehicle class and returns string by value
*/
std::string getSerialNumberOfPermitByMaxCharges(const TouristVehiclePointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("TouristVehiclePointerContainer is empty!!\n");

    auto it = std::max_element(data.begin(), data.end(), [](const TouristVehiclePointer& t1, const TouristVehiclePointer& t2){
        return t1->perHourBookingCharge() < t2->perHourBookingCharge();
    });

    return it->get()->permit()->serialNumber();
}

/*
    takes lvalue reference of container of TouristVehiclePointer, interger number where TouristVehiclePointer is shared ptr
    of TouristVehicle class and returns string by value
*/
TouristVehiclePointerContainer getFirstNInstances(const TouristVehiclePointerContainer &data, int n) {
    if (data.empty()) 
        throw CustomMessageException("TouristVehiclePointerContainer is empty!!\n");

    TouristVehiclePointerContainer result;
    int cnt = n;
    for (const TouristVehiclePointer& ptr: data) {
        if (cnt <= 0)
            break;
        result.push_back(ptr);
        cnt -= 1;
    }
    return result;
}
