#include <iostream>
#include <unordered_map>
#include "Employee.hpp"

void display(const std::unordered_map<int, Employee>& data) {
    for (auto& [key, val]: data) 
        std::cout << "Key is: " << key << "  Value is: " << val << std::endl; 
}

/*
    g++ Main.cpp -g -o app && time ./app && rm app
*/
int main() {
    std::unordered_map<int, Employee> data {
        std::pair<int, Employee>(10, Employee(10, "Krishna", "Pune"))
    };

    data.emplace(
        std::pair<int, Employee>(21, Employee(21, "Rohan", "Mumbai"))
    );

    data.emplace(
        std::pair<int, Employee>(33, Employee(33, "Kaveri", "Delhi"))
    );

    display(data);

    return 0;
}