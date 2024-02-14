#include "Functionalities.hpp"
#include <iostream>

int main() {
    // Create some Employee objects
    Employee emp1(1, "John", 50000.0, Developer("IT", 10));
    Employee emp2(2, "Alice", 60000.0, HR("HR Department", 5));
    Employee emp3(3, "Bob", 55000.0, Developer("Software", 8));
    Employee emp4(4, "Jane", 70000.0, HR("Recruitment", 3));

    // Store employees in a container
    std::vector<Employee> employees = { emp1, emp2, emp3, emp4 };

    // Get developers
    std::vector<Employee> developers = getDevelopers(employees);
    std::cout << "Developers: " << std::endl;
    for (const auto& dev : developers) {
        std::cout << "ID: " << dev.getId() << ", Name: " << dev.getName() << std::endl;
    }

    // Get HRs
    std::vector<Employee> hrs = getHRs(employees);
    std::cout << "\nHRs: " << std::endl;
    for (const auto& hr : hrs) {
        std::cout << "ID: " << hr.getId() << ", Name: " << hr.getName() << std::endl;
    }

    // Get data of employee by id
    int idToSearch = 3;
    Employee empData = getEmployeeById(employees, idToSearch);
    std::cout << "\nEmployee Data by ID " << idToSearch << ": " << std::endl;
    std::cout << "ID: " << empData.getId() << ", Name: " << empData.getName() << ", Salary: " << empData.getSalary() << std::endl;

    // Get specific data of an employee by id
    std::cout << "\nSpecific Employee Data by ID " << idToSearch << ": ";
    auto specificData = getSpecificEmployeeData(employees, idToSearch);
    if (std::holds_alternative<int>(specificData)) {
        std::cout << "Not Found or Unknown Type" << std::endl;
    } else {
        std::cout << std::get<int>(specificData) << std::endl;
    }

    return 0;
}