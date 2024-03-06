#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Automobile.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include <numeric>
#include <memory>
#include <array>
#include <algorithm>

using AutoPointer = std::shared_ptr<Automobile>;
using AutoPointerContainer = std::array<AutoPointer, 3>;    // std::array because its fixed size, random access using index

/*
    Function takes lvalue reference of container where container is std array of 3 AutoPointer
    and AutoPointer is the shared pointer of Automobile class and returns void
*/
void createObjects(AutoPointerContainer& data);

/*
    Function takes constant lvalue reference of container, string id where container is std array of 3 AutoPointer
    and AutoPointer is the shared pointer of Automobile class and returns void
*/
void displayGreenPassCostById(const AutoPointerContainer& data, std::string id);

/*
    Function takes constant lvalue reference of container where container is std array of 3 AutoPointer
    and AutoPointer is the shared pointer of Automobile class and returns void
*/
void displayAveragePrice(const AutoPointerContainer& data);

/*
    Function takes constant lvalue reference of container where container is std array of 3 AutoPointer
    and AutoPointer is the shared pointer of Automobile class and returns void
*/
void displayPrivilegeType(const AutoPointerContainer& data);


#endif // FUNCTIONALITIES_HPP
