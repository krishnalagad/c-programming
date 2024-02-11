#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

class Employee {
private:
    std::string name;
    double salary;

public:
    Employee() = delete;
    Employee(const std::string& name, double salary) : name(name), salary(salary) {}
    Employee(const Employee&) = delete;
    Employee(Employee&&) = delete;
    Employee& operator=(const Employee&) = delete;
    Employee& operator=(Employee&&) = delete;
    ~Employee() = default;

    // Getter for name
    std::string getName() const { return name; }

    // Getter for salary
    double getSalary() const { return salary; }
};

// Function to calculate the average salary of employees with a matching name
double averageSalaryByName(const std::vector<Employee>& employees, std::function<bool(const Employee&)> predicate, const std::string& name) {
    double sum = 0.0;
    int count = 0;

    // Iterate through the employees vector
    for (const auto& emp : employees) {
        // Check if the employee's name matches the given name and if the predicate returns true
        if (emp.getName() == name && predicate(emp)) {
            sum += emp.getSalary();
            count++;
        }
    }

    // Calculate and return the average salary
    return (count > 0) ? (sum / count) : 0.0;
}

int main() {
    // Sample vector of Employee objects
    std::vector<Employee> employees = {
        {"John", 50000.0},
        {"Alice", 60000.0},
        {"Bob", 55000.0},
        {"John", 52000.0},
        {"Alice", 58000.0}
    };

    // Lambda predicate function to filter employees based on salary
    auto salaryPredicate = [](const Employee& emp) {
        return emp.getSalary() > 55000.0; // Only employees with salary > 55000 will be considered
    };

    // Name of the employee to filter by
    std::string targetName = "John";

    // Calculate the average salary of employees with the specified name and matching predicate
    double averageSalary = averageSalaryByName(employees, salaryPredicate, targetName);

    // Output the result
    std::cout << "Average salary of employees named " << targetName << " with salary > 55000: " 
                << averageSalary << std::endl;

    return 0;
}
