#include <iostream>
#include <unordered_map>
#include <memory>
#include "Employee.hpp"

using EmpPointer = std::shared_ptr<Employee>;
using MapEntry = std::pair<int, const EmpPointer>;
using MapContainer = std::unordered_map<int, const EmpPointer>;

void display(MapContainer& data) {
    for (auto& [key, val]: data) 
        std::cout << "Key is: " << key << "  Value is: " << *val << std::endl; 
}

/*
    g++ Main2.cpp -g -o app && time ./app && rm app
*/
int main() {
    MapContainer data {
        MapEntry(10, std::make_shared<Employee>(10, "Krishna Lagad", "Pune"))
    };

    data.emplace(
        MapEntry(21, std::make_shared<Employee>(21, "Rohan Pandey", "Mumbai"))
    );

    data.emplace(
        MapEntry(33, std::make_shared<Employee>(33, "Kaveri Raina", "Delhi"))
    );

    display(data);

    if (auto itr = data.find(10); itr != data.end()) 
        std::cout << "\nEmployee with given ID is found: " << *(itr)->second << std::endl;
    else 
        std::cout << "Not Found!!" << std::endl;

    std::cout << "Number of buckets: " << data.bucket_count() << std::endl;
    std::cout << "Max possible size of hashtable: " << data.max_size() << std::endl;
    std::cout << "Size of bucket 0: " << data.bucket_size(0) << std::endl;
    std::cout << "In which bucket is key 10 present?: " << data.bucket(10) << std::endl;


    return 0;
}