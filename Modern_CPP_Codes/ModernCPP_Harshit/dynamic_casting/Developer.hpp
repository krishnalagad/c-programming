#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include "Employee.hpp"
#include "DeveloperDepartment.h"
#include <iostream>

class Developer : public Employee {
    private:
        int _developerExperience;
        DeveloperDepartment _developerDepartment;

    public:
        Developer() = delete;
        Developer(const Developer&) = delete;
        Developer(Developer&&) = delete;
        Developer& operator=(const Developer&) = delete;
        Developer& operator=(Developer&&) = delete;
        ~Developer() { std::cout << "Developer destroyeed!!\n"; }

        Developer(int id, std::string name, float salary, int exp, DeveloperDepartment dept);

        float calculateTax() override;


        friend std::ostream &operator<<(std::ostream &os, const Developer &rhs);
};

#endif // DEVELOPER_HPP
