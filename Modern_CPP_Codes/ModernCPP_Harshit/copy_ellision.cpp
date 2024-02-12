#include <iostream>

class Employee {
    private:
        int _eId;
        std::string _eName;
    public:
        Employee() = delete;
        Employee(int id, std::string name): _eId(id), _eName(name) {}
        Employee(const Employee&) {
            std::cout << "copy constructor called!!" << std::endl;
        }
        Employee(Employee&&) {
            std::cout << "move constructor called!!" << std::endl;
        }
        Employee& operator=(const Employee&) {
            std::cout << "copy assignment called!!" << std::endl;
            return *this;
        }
        Employee& operator=(Employee&&) {
            std::cout << "move assignment called!!" << std::endl;
            return *this;
        }
        ~Employee() = default;

        friend std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
            os << "_eId: " << rhs._eId
            << " _eName: " << rhs._eName;
            return os;
        }
};

Employee magic(int id, std::string name) {
    std::cout << "Middle man fuction called!!" << std::endl;
    return Employee(id, name);
}

/*
    g++ copy_ellision.cpp -g -o app && ./app
    g++ copy_ellision.cpp -fno-elide-constructors -g -o app && ./app    // to turn off the optimization
*/
int main() {
    Employee e1 = magic(101, "Krishna");    // Employee e1 is assigned a rvalue
    std::cout << e1 << std::endl;

    return 0;
}
