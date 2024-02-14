#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <string>
#include <variant>
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
};

#endif // EMPLOYEE_HPP
