#include <iostream>
#include "Functionalities.h"
#include "CarNotExistsException.h"

/*
    g++ Car.cpp Engine.cpp Main.cpp Functionalities.cpp -o app && ./app && rm app
*/
int main() {
    CarPointerContainer data;
    EngineContainer engineData;
    createObjects(data, engineData);
    try {
        std::string id = "C101";
        int resultHp = getHPByCarId(id, data);
        std::cout << "Horsepower of car is: " << resultHp << std::endl;
        getAvgHorsepowerByTypeAndPrice(EngineType::HYBRID, 80000, data);
        std::cout << "Combined price of Cars is " << getCombinedPriceOfTwoCars(data[0], data.at(2)) << std::endl;
        std::optional<CarPointerContainer> result = getCarsByEngineTorque(80, data);
        if (result.has_value()) 
            display(result.value());
    }
    catch( CarNotExistsException& e) {
        std::cout << e.what();
    }
    

    return 0;
}