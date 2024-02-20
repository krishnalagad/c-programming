#include <iostream>
#include "Functionalities.hpp"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp Automobile.cpp -g -o app && time ./app && rm app
*/
int main() {
    AutoPointerContainer data;
    createObjects(data);

    try{
        displayGreenPassCostById(data, "AUTO002");
        displayAveragePrice(data);
        displayPrivilegeType(data);
    } catch(CustomMessageException& e) {
        std::cerr << e.what() << '\n';
    }catch(RecordNotFoundException& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}