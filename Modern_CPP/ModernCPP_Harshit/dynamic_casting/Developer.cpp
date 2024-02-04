#include "Developer.hpp"

Developer::Developer(int id, std::string name, float salary, int exp, DeveloperDepartment dept)
    :Employee(id, name, salary), _developerExperience(exp), _developerDepartment(dept) {}


float Developer::calculateTax() {
    return 0.2f * this->eSalary();
}

std::ostream &operator<<(std::ostream &os, const Developer &rhs) {
    os << static_cast<const Employee &>(rhs)
       << " _developerExperience: " << rhs._developerExperience
       << " _developerDepartment: " << static_cast<int>(rhs._developerDepartment);
    return os;
}
