#include <iostream>
#include <variant>
#include <vector>

class Employee {
    private:
        
    public:
        Employee() = default;
        void display() { std::cout << "Employee siuuuu!!" << std::endl; }
        ~Employee() { std::cout << "Emp Object destroyed!!" << std::endl; }
};

class BusinessOwner {
    private:
        
    public:
        BusinessOwner() = default;
        void display() { std::cout << "BusinessOwner siuuuu!!" << std::endl; }
        ~BusinessOwner() { std::cout << "Business Object destroyed!!" << std::endl; }
};

/*
    g++ variant_demo2.cpp -o app && time ./app && rm app
        - std::variant implementation on stack memory
*/
int main() {
    std::vector<std::variant<Employee, BusinessOwner>> data;
    // data.emplace_back(Employee());   // creates temporary object
    // data.emplace_back(BusinessOwner());

    data.emplace_back(std::in_place_type<Employee>);    // directly add data at place
    data.emplace_back(std::in_place_type<BusinessOwner>);


    for (std::variant<Employee, BusinessOwner>& v: data) {
        std::visit([](auto&& val){ val.display(); }, v);
    }
    
    return 0;
}