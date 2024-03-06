#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Employee.hpp"
#include "BusinessOwner.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <variant>
#include <future>

using EmployeePointer = std::shared_ptr<Employee>;
using BusinessPointer = std::shared_ptr<BusinessOwner>;
using Variant = std::variant<EmployeePointer, BusinessPointer>;     
using VariantContainer = std::vector<Variant>;  // std::vector for random access and dynamic growth

/*
    Function takes lvalue reference of VariantContainer where VariantContainer is vector of Variant and
    Variant is the std::variant of EmployeePointer and BusinessPointer where EmployeePointer is shared
    ptr of Employee class and BusinessPointer is shared ptr of BusinessOwner class and returns void.
*/
void createObjects(VariantContainer& data);

/*
    Function takes constant lvalue reference of VariantContainer, integer where VariantContainer is vector 
    of Variant and Variant is the std::variant of EmployeePointer and BusinessPointer where EmployeePointer 
    is shared ptr of Employee class and BusinessPointer is shared ptr of BusinessOwner class and returns integer.
*/
int getCountOfBusinessInstances(const VariantContainer& data, int age);

/*
    Function takes constant lvalue reference of VariantContainer, integer where VariantContainer is vector 
    of Variant and Variant is the std::variant of EmployeePointer and BusinessPointer where EmployeePointer 
    is shared ptr of Employee class and BusinessPointer is shared ptr of BusinessOwner class and returns boolean.
*/
bool isEmployeeTaxableAmountAboveThreshold(const VariantContainer& data, int th);

/*
    Function takes constant lvalue reference of VariantContainer, std::promise where VariantContainer is vector 
    of Variant and Variant is the std::variant of EmployeePointer and BusinessPointer where EmployeePointer 
    is shared ptr of Employee class and BusinessPointer is shared ptr of BusinessOwner class and returns 
    Container of instances.
*/
VariantContainer getInstancesWithTaxPercentBelowThreshold(const VariantContainer& data, std::promise<int>& p);

#endif // FUNCTIONALITIES_HPP
