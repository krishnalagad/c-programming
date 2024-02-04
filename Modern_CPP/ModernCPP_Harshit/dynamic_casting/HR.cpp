#include <iostream>
#include "HR.hpp"

std::ostream &operator<<(std::ostream &os, const HR &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " __hrTeamSize: " << rhs.__hrTeamSize
       << " _hrSpecialization: " << static_cast<int> (rhs._hrSpecialization);
    return os;
}

HR::HR(int id, std::string name, float salary, int hrTeamSize, HrSpecialization specialization)
    : Employee(id, name, salary) {}

float HR::calculateTax() {
    return 0.1f * eSalary();
}
