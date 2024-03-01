#include <iostream>
#include <unordered_map>
#include "Employee.hpp"

using MapEntry = std::pair<int, const Employee>;
using MapContainer = std::unordered_map<int, const Employee>;

void display(MapContainer& data) {
    for (auto& [key, val]: data) 
        std::cout << "Key is: " << key << "  Value is: " << val << std::endl; 
}

/*
    g++ Main.cpp -g -o app && time ./app && rm app
*/
int main() {
    MapContainer data {
        MapEntry(10, Employee(10, "Krishna", "Pune"))
    };

    data.emplace(
        MapEntry(21, Employee(21, "Rohan", "Mumbai"))
    );

    data.emplace(
        MapEntry(33, Employee(33, "Kaveri", "Delhi"))
    );

    display(data);

    return 0;
}