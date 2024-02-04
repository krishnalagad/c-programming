#include "Employee.hpp"
#include "HR.hpp"
#include "Developer.hpp"
#include <vector>

int main() {
    Employee* ptr1 = new HR(101, "Krishna", 25000.0f, 10, HrSpecialization::RECRUITMENT);
    Employee* ptr2 = new Developer(201, "Lagad", 25000.0f, 12, DeveloperDepartment::SYSTEM_DEVELOPER);
    std::vector<Employee*> data {ptr1, ptr2};

    for(Employee* ptr: data) {
        std::cout << "Taxes for employee "
                  << ptr->eName() << " is " << ptr->calculateTax() << std::endl;
    }

    delete ptr2;
    delete ptr1;

    return 0;
}