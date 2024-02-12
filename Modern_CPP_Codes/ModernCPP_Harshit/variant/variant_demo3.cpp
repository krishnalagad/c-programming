#include <iostream>
#include <variant>
#include <vector>
#include <memory>

class Employee {
    private:
        
    public:
        Employee() = default;
        void display() { std::cout << "Employee siuuuu!!" << std::endl; }
        ~Employee() { std::cout << "Employee Object destroyed!!" << std::endl; }
};

class BusinessOwner {
    private:
        
    public:
        BusinessOwner() = default;
        void display() { std::cout << "BusinessOwner siuuuu!!" << std::endl; }
        ~BusinessOwner() { std::cout << "Businness Object destroyed!!" << std::endl; }
};

using EPointer = std::shared_ptr<Employee>;
using BPointer = std::shared_ptr<BusinessOwner>;


/*
    g++ variant_demo3.cpp -o app && time ./app && rm app
        - - std::variant implementation on Heap memory
*/
int main() {
    std::vector<std::variant<EPointer, BPointer>> data(2);
    data[0] = std::make_shared<Employee>();
    data[1] = std::make_shared<BusinessOwner>();

    for (std::variant<EPointer, BPointer>& v: data) {
        std::visit([](auto&& val){ val->display(); }, v);
    }
    
    return 0;
}