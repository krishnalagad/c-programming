#include "Functionalities.hpp"
#include "CarType.hpp"
#include <future>

/*
    Client code:
        g++ Main.cpp Functionalities.cpp EvCar.cpp ICECar.cpp -lpthread -o app && time ./app && rm app
*/
int main() {
    CarVariantContainer data;

    // functionality to add data into container
    std::future<void> r1 = std::async(std::launch::async, createObjects, std::ref(data));
    r1.get();

    try {
        // functionality to check the tank capacity
        std::future<bool> r2 = std::async(std::launch::async, isFuelTankCapacityAbove30, std::ref(data));
        bool res = r2.get();
        std::string result = res ? "Yeahhhh!!" : "NOOO!!!";
        std::cout << "Is Fuel tank capacity above 30: " << result << std::endl;

        std::cout << "\n";
        std::future<std::optional<CarVariantContainer>> r7 = std::async(std::launch::async, getFirstNCarsBasedOnType, 
                                                                std::ref(data), CarType::EvCar_Type, 2);
        std::optional<CarVariantContainer> cvc = r7.get();
        if (cvc.has_value()) {
            CarVariantContainer container = cvc.value();
            for (const CarVariant& v: container) {
                std::cout << *std::get<EvCarPointer>(v).get();
            }
        }

        // functionality to print count of all the EvCar instances
        std::cout << "\n";
        std::future<void> r3 = std::async(std::launch::async, printCountOfEvCarInstances, std::ref(data));
        r3.get();

        std::future<std::string> r4 = std::async(std::launch::async, getChassisTypeById, std::ref(data), 103);
        std::string resStr = r4.get();
        std::cout << "Chassis Type of EvCar of given ID is: " << resStr << std::endl;

        std::future<float> r5 = std::async(std::launch::async, getTotalBatteryCapacityOfEvCars, std::ref(data));
        float tot = r5.get();
        std::cout << "Total Battery capacity of all the EvCars is: " << tot << std::endl;

        std::cout << "\n";
        std::future<void> r6 = std::async(std::launch::async, printDataOfCarObject, std::ref(data), 3);
        r6.get();

    } catch(CustomMessageException& e) {
        std::cerr << e.what() << '\n';
    } catch(RecordNotFoundException& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}