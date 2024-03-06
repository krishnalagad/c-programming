#include <iostream>
#include "Functionalities.hpp"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp Employee.cpp BusinessOwner.cpp -lpthread -o app && time ./app && rm app
*/
int main() {

    VariantContainer data;
    std::future<void> r1 = std::async(std::launch::async, createObjects, std::ref(data));
    r1.get();

    auto newFn = std::bind(getCountOfBusinessInstances, std::placeholders::_1, 40);
    std::future<int> r2 = std::async(std::launch::async, newFn, std::ref(data));
    int res = r2.get();
    std::cout << "\nCount is: " << res << std::endl;

    std::future<bool> r3 = std::async(std::launch::async, isEmployeeTaxableAmountAboveThreshold, std::ref(data), 10000);
    bool flag = r3.get();
    std::string str = flag ? "YEAHH" : "NOOOO";
    std::cout << "\nIs instance present: " << str << std::endl << "\n";

    std::promise<int> p;
    std::future<VariantContainer> r4 = std::async(std::launch::async, getInstancesWithTaxPercentBelowThreshold, std::ref(data), std::ref(p));
    p.set_value(10);

    VariantContainer resVar = r4.get();
    for(const Variant& v: resVar) {
        if (std::holds_alternative<EmployeePointer>(v)) {
            std::cout << *std::get<EmployeePointer>(v) << std::endl;
        }
        if (std::holds_alternative<BusinessPointer>(v)) {
            std::cout << *std::get<BusinessPointer>(v) << std::endl;
        }
    }
    
    return 0;
}