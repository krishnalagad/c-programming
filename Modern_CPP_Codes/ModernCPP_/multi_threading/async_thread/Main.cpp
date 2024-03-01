#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <mutex>
#include <condition_variable>
#include <variant>

// Forward declarations
// class Employee;
// class Developer;
// class HR;

class Employee {
private:
    int _id;
    std::string _name;
    float _salary;
    std::variant<Developer, HR> _employeeType;

public:
    Employee(Employee&&) = default;
    Employee(const Employee&) = default;
    Employee& operator=(const Employee&) = default;
    Employee& operator=(Employee&&) = default;
    Employee(int id, const std::string& name, float salary, const std::variant<Developer, HR>& employeeType)
        : _id(id), _name(name), _salary(salary), _employeeType(employeeType) {}

    int getId() const { return _id; }
    const std::string& getName() const { return _name; }
    float getSalary() const { return _salary; }
    const std::variant<Developer, HR>& getEmployeeType() const { return _employeeType; }
};

class Developer {
private:
    int _pendingTasks;
    std::string _devDepartment;

public:
    Developer(const Developer&) = default;
    Developer(Developer&&) = default;
    Developer& operator=(const Developer&) = default;
    Developer& operator=(Developer&&) = default;
    Developer(int pendingTasks, const std::string& devDepartment)
        : _pendingTasks(pendingTasks), _devDepartment(devDepartment) {}

    int getPendingTasks() const { return _pendingTasks; }
    const std::string& getDevDepartment() const { return _devDepartment; }
};

class HR {
private:
    int _pendingInterviews;
    std::string _hrDepartment;

public:
    HR(const HR&) = default;
    HR(HR&&) = default;
    HR& operator=(const HR&) = default;
    HR& operator=(HR&&) = default;
    HR(int pendingInterviews, const std::string& hrDepartment)
        : _pendingInterviews(pendingInterviews), _hrDepartment(hrDepartment) {}

    int getPendingInterviews() const { return _pendingInterviews; }
    const std::string& getHrDepartment() const { return _hrDepartment; }
};

class EmployeeManager {
private:
    std::mutex _mutex;
    std::condition_variable _cv;
    std::vector<Employee> _employees;

public:
    void addEmployee(const Employee& emp) {
        std::lock_guard<std::mutex> lock(_mutex);
        _employees.push_back(emp);
        _cv.notify_all(); // Notify all waiting threads
    }

    std::vector<Employee> getDevelopers() {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this] { return !_employees.empty(); });

        std::vector<Employee> developers;
        for (const auto& emp : _employees) {
            if (std::holds_alternative<Developer>(emp.getEmployeeType())) {
                developers.push_back(emp);
            }
        }
        return developers;
    }

    std::vector<Employee> getHRs() {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this] { return !_employees.empty(); });

        std::vector<Employee> hrs;
        for (const auto& emp : _employees) {
            if (std::holds_alternative<HR>(emp.getEmployeeType())) {
                hrs.push_back(emp);
            }
        }
        return hrs;
    }

    Employee getEmployeeById(int id) {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this] { return !_employees.empty(); });

        auto it = std::find_if(_employees.begin(), _employees.end(),
                               [id](const Employee& emp) { return emp.getId() == id; });
        if (it != _employees.end()) {
            return *it;
        }
        throw std::runtime_error("Employee not found");
    }

    int getPendingTasksOrInterviews() {
        std::unique_lock<std::mutex> lock(_mutex);
        _cv.wait(lock, [this] { return !_employees.empty(); });

        int total = 0;
        for (const auto& emp : _employees) {
            if (std::holds_alternative<Developer>(emp.getEmployeeType())) {
                total += std::get<Developer>(emp.getEmployeeType()).getPendingTasks();
            } else if (std::holds_alternative<HR>(emp.getEmployeeType())) {
                total += std::get<HR>(emp.getEmployeeType()).getPendingInterviews();
            }
        }
        return total;
    }
};
/*
    g++ Main.cpp -o app && time ./app && rm app
*/
int main() {
    EmployeeManager empManager;

    // Add some employees
    empManager.addEmployee(Employee(1, "John", 50000.0, Developer(5, "Engineering")));
    empManager.addEmployee(Employee(2, "Alice", 60000.0, HR(3, "Recruitment")));
    empManager.addEmployee(Employee(3, "Bob", 55000.0, Developer(8, "Development")));
    empManager.addEmployee(Employee(4, "Eva", 58000.0, HR(6, "Training")));

    // Use async to call each function in a separate thread
    std::future<std::vector<Employee>> developersFuture = std::async([&empManager]() { return empManager.getDevelopers(); });
    std::future<std::vector<Employee>> hrsFuture = std::async([&empManager]() { return empManager.getHRs(); });
    std::future<Employee> empByIdFuture = std::async([&empManager]() { return empManager.getEmployeeById(3); });
    std::future<int> pendingTasksOrInterviewsFuture = std::async([&empManager]() { return empManager.getPendingTasksOrInterviews(); });

    // Get results from futures
    std::vector<Employee> developers = developersFuture.get();
    std::vector<Employee> hrs = hrsFuture.get();
    Employee empById = empByIdFuture.get();
    int pendingTasksOrInterviews = pendingTasksOrInterviewsFuture.get();

    // Display results
    std::cout << "Developers:\n";
    for (const auto& dev : developers) {
        std::cout << dev.getName() << ", ";
    }
    std::cout << "\n";

    std::cout << "HRs:\n";
    for (const auto& hr : hrs) {
        std::cout << hr.getName() << ", ";
    }
    std::cout << "\n";

    std::cout << "Employee by ID (3): " << empById.getName() << "\n";

    std::cout << "Total pending tasks or interviews: " << pendingTasksOrInterviews << "\n";

    return 0;
}