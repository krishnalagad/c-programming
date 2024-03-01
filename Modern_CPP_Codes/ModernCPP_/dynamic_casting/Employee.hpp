#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>

class Employee {
    private:
        int _eId;
        std::string _eName;
        float _eSalary;

    public:
        Employee() = default;
        Employee(const Employee&) = delete;
        Employee(Employee&&) = delete;
        Employee& operator=(const Employee&) = delete;
        Employee& operator=(Employee&&) = delete;
        virtual ~Employee() { std::cout << "Emmployee destroyeed!!\n"; }

        Employee(int id, std::string name, float salary);

        virtual float calculateTax() = 0;

        std::string eName() const { return _eName; }
        void setEName(const std::string &eName) { _eName = eName; }

        float eSalary() const { return _eSalary; }
        void setESalary(float eSalary) { _eSalary = eSalary; }

        int eId() const { return _eId; }

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_HPP
