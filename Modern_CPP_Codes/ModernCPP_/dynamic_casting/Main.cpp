#include "Employee.hpp"
#include "HR.hpp"
#include "Developer.hpp"
#include <vector>
#include <memory>

int main() {

    std::shared_ptr<Employee> ptr = std::make_shared<HR>(101, "Krishna", 25000.0f, 112, HrSpecialization::RECRUITMENT);

    // HR has a getter called hrTeamSize()
    std::shared_ptr<HR> fullPtr = std::dynamic_pointer_cast<HR>(ptr);
    std::cout << "Team Size: " << fullPtr->hrTeamSize() << std::endl 
                << "Emp Id: " << fullPtr->eId() << std::endl 
                << "Specialization: " << static_cast<int>(fullPtr->hrSpecialization()) << std::endl;


    // Employee* ptr1 = new HR(101, "Krishna", 25000.0f, 10, HrSpecialization::RECRUITMENT);
    // Employee* ptr2 = new Developer(201, "Lagad", 25000.0f, 12, DeveloperDepartment::SYSTEM_DEVELOPER);
    // std::vector<Employee*> data {ptr1, ptr2};

    // for(Employee* ptr: data) {
    //     std::cout << "Taxes for employee "
    //               << ptr->eName() << " is " << ptr->calculateTax() << std::endl;
    // }

    // delete ptr2;
    // delete ptr1;

    return 0;
}