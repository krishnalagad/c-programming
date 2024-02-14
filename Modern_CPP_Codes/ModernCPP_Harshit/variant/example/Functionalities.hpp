#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <vector>
#include <variant>
#include <functional>
#include <vector>
#include "Employee.hpp"

using Container = std::vector<Employee>;

// Function to add data into container
void createObjects(Container& data);

// Function to filter employees with Developer type and return a container
std::vector<Employee> getDevelopers(const std::vector<Employee>& employees);

// Function to filter employees with HR type and return a container
std::vector<Employee> getHRs(const std::vector<Employee>& employees);

// Function to get employee data by id
Employee getEmployeeById(const std::vector<Employee>& employees, int id);

// Function to get specific data of an employee by id
int getSpecificEmployeeData(const std::vector<Employee>& employees, int id);


#endif // FUNCTIONALITIES_HPP
