#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <variant>
#include <ostream>
#include "Developer.hpp"
#include "HR.hpp"

class Employee {
    private:
        int _id;
        std::string _name;
        float _salary;
        std::variant<Developer, HR> _empTypeData;

    public:
        Employee(int id, const std::string& name, float salary, const std::variant<Developer, HR>& empTypeData)
            : _id(id), _name(name), _salary(salary), _empTypeData(empTypeData) {}

        int getId() const { return _id; }
        const std::string& getName() const { return _name; }
        float getSalary() const { return _salary; }
        const std::variant<Developer, HR>& getEmpTypeData() const { return _empTypeData; }

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary;
        if (std::holds_alternative<Developer>(rhs.getEmpTypeData())) {
            Developer dev = std::get<Developer>(rhs.getEmpTypeData());
            os << "\n_Developer: \n" << dev;
        } 
        if (std::holds_alternative<HR>(rhs.getEmpTypeData())) {
            HR hr = std::get<HR>(rhs.getEmpTypeData());
            os << "\n_Hr: \n" << hr;
        }
    os << "\n";
    return os;
}

#endif // EMPLOYEE_HPP
