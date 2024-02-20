#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Vehicle.hpp"
#include "ServiceType.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <optional>
#include <map>
#include <numeric>

using VehicleContainer = std::vector<Vehicle>;
using RecordsContainer = std::vector<ServiceRecord>;

/*
    Function takes lvalue reference of VehicleContainer, RecordsContainer  where VehicleContainer
    is std vector of Vehicle class and RecordsContainer is a vector of ServiceRecord Class
    and return type is void
*/
void createObjects(VehicleContainer &data, RecordsContainer& records);

/*
    Function takes constant lvalue reference of VehicleContainer, integer n where VehicleContainer
    is std vector of Vehicle class and return type is std optional of list
*/
std::optional<std::list<Vehicle>> getLastInstancesOfVehicles(const VehicleContainer &data, int n);

/*
    Function takes constant lvalue reference of VehicleContainer, list of strings where VehicleContainer
    is std vector of Vehicle class and return type is std map of string and string
*/
std::map<std::string, std::string> getKeyValPairOfIds(const VehicleContainer &data, const std::list<std::string>& idList);

/*
    Function takes constant lvalue reference of VehicleContainer where VehicleContainer
    is std vector of Vehicle class and return type is std map of string and string
*/
std::map<std::string, ServiceRecord> getKeyValOfIdAndService(const VehicleContainer &data);

/*
    Function takes constant lvalue reference of VehicleContainer where VehicleContainer
    is std vector of Vehicle class and return float
*/
float getAverageCharges(const VehicleContainer &data);

/*
    Function takes constant lvalue reference of VehicleContainer. string id where VehicleContainer
    is std vector of Vehicle class and return string
*/
std::string getVehicleIdByServiceId(const VehicleContainer &data, std::string serviceId);

#endif // FUNCTIONALITIES_HPP
