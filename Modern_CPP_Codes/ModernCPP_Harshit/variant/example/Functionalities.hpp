#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <vector>
#include <variant>
#include <functional>
#include "Employee.hpp"


// Function to filter employees with Developer type and return a container
std::vector<Employee> getDevelopers(const std::vector<Employee>& employees) {
    std::vector<Employee> developers;
    for (const auto& emp : employees) {
        if (std::holds_alternative<Developer>(emp.getEmpTypeData())) {
            developers.push_back(emp);
        }
    }
    return developers;
}

// Function to filter employees with HR type and return a container
std::vector<Employee> getHRs(const std::vector<Employee>& employees) {
    std::vector<Employee> hrs;
    for (const auto& emp : employees) {
        if (std::holds_alternative<HR>(emp.getEmpTypeData())) {
            hrs.push_back(emp);
        }
    }
    return hrs;
}

// Function to get employee data by id
Employee getEmployeeById(const std::vector<Employee>& employees, int id) {
    auto it = std::find_if(employees.begin(), employees.end(), [id](const Employee& emp) {
        return emp.getId() == id;
    });
    if (it != employees.end()) {
        return *it;
    } else {
        // Return a default constructed Employee object if id not found
        return Employee(-1, "", 0.0, Developer("", 0));
    }
}

// Function to get specific data of an employee by id
std::variant<int, int> getSpecificEmployeeData(const std::vector<Employee>& employees, int id) {
    auto emp = getEmployeeById(employees, id);
    if (std::holds_alternative<HR>(emp.getEmpTypeData())) {
        auto hrData = std::get<HR>(emp.getEmpTypeData());
        return hrData.getPendingInterviews();
    } else if (std::holds_alternative<Developer>(emp.getEmpTypeData())) {
        auto devData = std::get<Developer>(emp.getEmpTypeData());
        return devData.getTasksAssigned();
    } else {
        // Return a variant with an error value
        return std::variant<int, int>{-1}; // or std::variant<int, int>{std::in_place_index<0>, -1}
    }
}


#endif // FUNCTIONALITIES_HPP
