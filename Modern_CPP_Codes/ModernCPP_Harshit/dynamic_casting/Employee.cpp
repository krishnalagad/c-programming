#include <iostream>
#include "Employee.hpp"

std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_eId: " << rhs._eId
       << " _eName: " << rhs._eName
       << " _eSalary: " << rhs._eSalary;
    return os;
}

Employee::Employee(int id, std::string name, float salary)
    : _eId(id), _eName(name), _eSalary(salary) {}
