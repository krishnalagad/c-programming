#include "Functionalities.hpp"
#include <iostream>
/*
    g++ Main.cpp Functionalities.cpp -g -o app && time ./app && rm app
*/
int main() {

    // Store employees in a container
    Container employees;
    createObjects(employees);

    // Get developers
    std::vector<Employee> developers = getDevelopers(employees);
    std::cout << "Developers: " << std::endl;
    for (const Employee& dev : developers) {
        // std::cout << "ID: " << dev.getId() << ", Name: " << dev.getName() << std::endl;
        std::cout << dev;
    }

    // Get HRs
    std::vector<Employee> hrs = getHRs(employees);
    std::cout << "\nHRs: " << std::endl;
    for (const Employee& hr : hrs) {
        // std::cout << "ID: " << hr.getId() << ", Name: " << hr.getName() << std::endl;
        std::cout << hr;
    }

    // Get data of employee by id
    int idToSearch = 3;
    Employee empData = getEmployeeById(employees, idToSearch);
    std::cout << "\nEmployee Data by ID " << idToSearch << ": " << std::endl;
    // std::cout << "ID: " << empData.getId() << ", Name: " << empData.getName() << ", Salary: " << empData.getSalary() << std::endl;
    std::cout << empData << std::endl;

    // Get specific data of an employee by id
    std::cout << "\nSpecific Employee Data by ID " << idToSearch << ": ";
    int specificData = getSpecificEmployeeData(employees, idToSearch);
    if (specificData == -1) {
        std::cout << "Not Found or Unknown Type" << std::endl;
    } else {
        std::cout << specificData << std::endl;
    }

    return 0;
}