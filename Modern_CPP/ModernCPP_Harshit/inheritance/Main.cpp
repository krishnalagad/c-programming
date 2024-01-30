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

    // std::cout << std::dynamic_pointer_cast<Car>(data[0])->carType();
    std::cout << *data.at(1) << std::endl;

    return 0;
}