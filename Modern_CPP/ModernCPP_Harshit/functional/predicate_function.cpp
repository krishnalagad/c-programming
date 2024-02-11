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
        Employee(Employee&&) = default;
        Employee& operator=(const Employee&) = delete;
        Employee& operator=(Employee&&) = delete;
        ~Employee() = default;

        // Getter for name
        std::string getName() const { return name; }

        // Getter for salary
        double getSalary() const { return salary; }
};

// Function to calculate the average salary of employees with a matching name
double averageSalaryByName(const std::vector<Employee>& employees, std::function<bool(const Employee&, const std::string&)> predicate, const std::string& name) {
    double sum = 0.0;
    int count = 0;

    // Iterate through the employees vector
    for (const Employee& emp : employees) {
        // Check if the employee's name matches the given name and if the predicate returns true
        if (predicate(emp, name)) {
            sum += emp.getSalary();
            count++;
        }
    }

    // Calculate and return the average salary
    return (count > 0) ? (sum / count) : 0.0;
}

/*
    Client code:
        g++ predicate_function.cpp -g -o app && time ./app && rm app
*/
int main() {
    // Sample vector of Employee objects
    std::vector<Employee> employees;

    // Add employees one by one using push_back
    employees.push_back(Employee("John", 50000.0));
    employees.push_back(Employee("Alice", 60000.0));
    employees.push_back(Employee("Bob", 55000.0));
    employees.push_back(Employee("John", 52000.0));
    employees.push_back(Employee("John", 58000.0));

    // Lambda predicate function to filter employees based on salary
    std::function<bool(const Employee&, const std::string&)> salaryPredicate = [](const Employee& emp, const std::string& targetName) -> bool {
        return emp.getName() == targetName;     // only employees with matching name
    };

    // Name of the employee to filter by name
    std::string targetName = "John";

    // Calculate the average salary of employees with the specified name and matching predicate
    double averageSalary = averageSalaryByName(employees, salaryPredicate, targetName);

    // Output the result
    std::cout << "Average salary of employees named " << targetName << " : " << averageSalary << std::endl;

    return 0;
}

