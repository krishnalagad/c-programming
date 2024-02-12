#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <ostream>

class Employee {
    private:
        int _id;
        std::string _name;
        std::string _location;
        
    public:
        Employee() = delete;
        Employee(const Employee&) = default;
        Employee(Employee&&) = default;
        Employee(int id, std::string name, std::string location): _id(id), _name(name), _location(location) {}
        Employee& operator=(const Employee&) = delete;
        Employee& operator=(Employee&&) = delete;
        ~Employee() = default;

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _location: " << rhs._location;
    return os;
}

#endif // EMPLOYEE_HPP
