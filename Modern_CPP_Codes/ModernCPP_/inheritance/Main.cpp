#include <iostream>
#include "Functionalities.h"

int main() {
    DataContainer data;
    createObjects(data);
    try {
        std::cout << "Total tax: " << calculateTotalRegistrationTax(data) << std::endl;
    } catch(std::runtime_error& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << *data[1] << std::endl;     // this will print fields of Vehicle class only
    
    // this will print Vehicle class field as well as Car class fields.
    std::cout << *std::dynamic_pointer_cast<Car>(data[1]) << std::endl;
    // std::cout << *data.at(1) << std::endl;

    return 0;
}