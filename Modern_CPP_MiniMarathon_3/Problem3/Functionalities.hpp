#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <vector>
#include <memory>
#include <variant>
#include <optional>
#include <algorithm>
#include <numeric>
#include "EvCar.hpp"
#include "ICECar.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include "CarType.hpp"

using EvCarPointer = std::shared_ptr<EvCar>;
using ICECarPointer = std::shared_ptr<ICECar>;
using CarVariant = std::variant<EvCarPointer, ICECarPointer>;
using CarVariantContainer = std::vector<CarVariant>;


/*
    Function takes lvalue reference of CarVariantContainer where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns void
*/
void createObjects(CarVariantContainer& data);

/*
    Function takes constant lvalue reference of CarVariantContainer, Enum and integer n where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns std::optional of CarVariantContainer
*/
std::optional<CarVariantContainer> getFirstNCarsBasedOnType(const CarVariantContainer& data, CarType type, int n);

/*
    Function takes constant lvalue reference of CarVariantContainer where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns boolean
*/
bool isFuelTankCapacityAbove30(const CarVariantContainer& data);

/*
    Function takes constant lvalue reference of CarVariantContainer where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns void
*/
void printCountOfEvCarInstances(const CarVariantContainer& data);

/*
    Function takes constant lvalue reference of CarVariantContainer, integer id where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns string Chassis type
*/
std::string getChassisTypeById(const CarVariantContainer& data, int id);

/*
    Function takes constant lvalue reference of CarVariantContainerwhere CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns float
*/
float getTotalBatteryCapacityOfEvCars(const CarVariantContainer& data);

/*
    Function takes constant lvalue reference of CarVariantContainer, integer n where CarVariantContainer is std::vector 
    of CarVariant and CarVariant is std::variant of shared pointers of EvCar class and ICECar class
    and returns void
*/
void printDataOfCarObject(const CarVariantContainer& data, int n);

#endif // FUNCTIONALITIES_HPP
