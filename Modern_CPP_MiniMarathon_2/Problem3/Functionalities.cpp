#include "Functionalities.hpp"

/*
    Implementation of all the functionalities of this project goes here in this file
*/

/*
    This function takes lvalue reference of Container where Container is
    and returns void
*/

void createObjects(CarPointerContainer &data) {
    /*
        2 objects of EV on heap
    */
    data.push_back(
        std::make_shared<EvCar>(
            23000.0f, "Model1", CarType::PRIVATE_CAR, 4, 60.0f));
    data.push_back(
        std::make_shared<EvCar>(
            26000.0f, "Model2", CarType::TOURIST_PERMIT_CAR, 7, 70.0f));

    /*
        3 objects of IC on heap
    */

    data.push_back(
        std::make_shared<ICEngineCar>(
            24000.0f, "Model3", CarType::PRIVATE_CAR, 4, 10, FuelType::PETROL ));
     data.push_back(
        std::make_shared<ICEngineCar>(
            26000.0f, "Model4", CarType::PRIVATE_CAR, 4, 13, FuelType::DIESEL ));
     data.push_back(
        std::make_shared<ICEngineCar>(
            26000.0f, "Model5", CarType::PRIVATE_CAR, 4, 20, FuelType::PETROL ));
            
}

float carTypeAverageInsuranceCost(const CarPointerContainer &data, CarType type) {
    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");

    int ans = 0.0f;
    for (const CarPointer& ptr: data) {
        if (type == ptr->carType()) {
            ans += ptr->calculateInsuranceCost();
        }
    }
    return ans;
}

// std::optional<CarPointerContainer> getInstancesWithConditions(const CarPointerContainer &data) {
    // if (data.empty()) 
    //     throw CustomMessageException("Data container is empty!!");

//     CarPointerContainer result;
//     for (const CarPointer& ptr: data) {
//         if 
//     }
// }

void display(const CarPointerContainer& data) {

    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");

    for (int i = 0; i < data.size(); i++){
        std::cout << *data[i] <<std::endl;
    }
}
