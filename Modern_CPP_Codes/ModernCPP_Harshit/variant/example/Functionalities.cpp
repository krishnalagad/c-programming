#include "Functionalities.hpp"

void createObjects(Container &data) {
    data.push_back(Employee (1, "John", 50000.0, Developer("IT", 10)));
    data.push_back(Employee (2, "Alice", 60000.0, HR("HR Department", 5)));
    data.push_back(Employee (3, "Bob", 55000.0, Developer("Software", 8)));
    data.push_back(Employee (4, "Jane", 70000.0, HR("Recruitment", 3)));
}

std::vector<Employee> getDevelopers(const std::vector<Employee> &employees)
{
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
int getSpecificEmployeeData(const std::vector<Employee>& employees, int id) {
    Employee emp = getEmployeeById(employees, id);
    if (std::holds_alternative<HR>(emp.getEmpTypeData())) {
        auto hrData = std::get<HR>(emp.getEmpTypeData());
        return hrData.getPendingInterviews();
    } else if (std::holds_alternative<Developer>(emp.getEmpTypeData())) {
        auto devData = std::get<Developer>(emp.getEmpTypeData());
        return devData.getTasksAssigned();
    } else {
        return -1; 
    }
}

// std::variant<int, int> getSpecificEmployeeData(const std::vector<Employee>& employees, int id) {
//     Employee emp = getEmployeeById(employees, id);
//     if (std::holds_alternative<HR>(emp.getEmpTypeData())) {
//         auto hrData = std::get<HR>(emp.getEmpTypeData());
//         return std::variant<int, int>(hrData.getPendingInterviews(), int(-1));
//     } else if (std::holds_alternative<Developer>(emp.getEmpTypeData())) {
//         auto devData = std::get<Developer>(emp.getEmpTypeData());
//         return std::variant<int, int>(int(-1), devData.getTasksAssigned());
//     } else {
//         return -1; // Returning -1 if the employee type is neither HR nor Developer
//     }
// }
