#include "Functionalities.hpp"

/*
    Client code goes here
    - g++ Main.cpp Functionalities.cpp -o app && ./app && rm app
*/
int main() {
    CarPointerContainer data;
    createObjects(data);

    std::cout << "\nAverage Insuarance Cost is: " << carTypeAverageInsuranceCost(data, CarType::PRIVATE_CAR) << std::endl;
    display(data);

    return 0;
}