#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include "EmployeeType.hpp"

class Employee {
    private:
        const int _regId;
        std::string _name;
        EmployeeType _type;
        int _age;
        int _taxableAmount;
        unsigned short _taxPercent;
        
    public:
        Employee() = delete;
        Employee(const Employee&) = default;
        Employee(Employee&&) = default;
        Employee& operator=(const Employee&) = default;
        Employee& operator=(Employee&&) = default;
        ~Employee() = default;

        Employee(int id, std::string name, EmployeeType type, int age, int amount, unsigned short percent);

        int regId() const { return _regId; }

        std::string name() const { return _name; }
        void setName(const std::string &name) { _name = name; }

        EmployeeType type() const { return _type; }
        void setType(const EmployeeType &type) { _type = type; }

        int taxableAmount() const { return _taxableAmount; }
        void setTaxableAmount(int taxableAmount) { _taxableAmount = taxableAmount; }

        unsigned short taxPercent() const { return _taxPercent; }
        void setTaxPercent(unsigned short taxPercent) { _taxPercent = taxPercent; }

        int age() const { return _age; }
        void setAge(int age) { _age = age; }

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_HPP
