#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "bike.h"
#include "vehicleNotFoundException.h"

double getAvgOfvehicle(int cat, Car* cars, Bike* bikes) {
    double sum = 0;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < 3; i++){
        if (cat == cars[i].getCarCategory()) {
            sum += cars[i].getExPrice();
            count += 1;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++){
        if (cat == bikes[i].getBikeCategory()) {
            sum += bikes[i].getExPrice();
            count += 1;
            flag = true;
        }
    }
    // if(!flag) 
    //     throw VehicleNotFoundException();

    return sum / count;
}

int getCountOnCategory(int cat, Car* cars, Bike* bikes) {
    bool flag = false;
    int count = 0;
    for (int i = 0; i < 3; i++){
        if (cat == cars[i].getCarCategory()) {
            count += 1;
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++){
        if (cat == bikes[i].getBikeCategory()) {
            count += 1;
            flag = true;
        }
    }
    if(!flag) 
        throw VehicleNotFoundException();

    return count;
}

void getVehicleByChassisNumber(int no, Vehicle* cars, Vehicle* bikes) {
    bool flag = false;
    for (int i = 0; i < 3; i++){
        if (no == cars[i].getChassisNumber()) {
            cars[i].display();
            flag = true;
        }
    }
    for (int i = 0; i < 3; i++){
        if (no == bikes[i].getChassisNumber()) {
            bikes[i].display();
            flag = true;
        }
    }

    if(!flag)
        throw VehicleNotFoundException();
}

int main() {

    Vehicle* cars = new Car[3];
    std::cout<<"---------Enter data for your Cars----------\n";
    for (int i = 0; i < 3; i++)
        std::cin>>cars[i];
    
    std::cout<<"---------Your Cars Data----------\n";
    for (int i = 0; i < 3; i++)
        cars[i].display();

    Vehicle* bikes = new Bike[3];
    std::cout<<"---------Enter data for your Bikes----------\n";
    for (int i = 0; i < 3; i++)
        std::cin>>bikes[i];

    std::cout<<"---------Your Bikes Data----------\n";
    for (int i = 0; i < 3; i++)
        bikes[i].display();

    // find by chassis number
    std::cout<<"\nEnter chassis number to search: ";
    int temp;
    getchar();
    std::cin>>temp;
    try {
        Car *c =  dynamic_cast<Car*>(cars);
        Bike *b = dynamic_cast<Bike*>(bikes);
        // getVehicleByChassisNumber(temp, cars, bikes);
        getVehicleByChassisNumber(temp, c, b);
    } catch(VehicleNotFoundException ex) {
        std::cout<<"\n"<<ex.what();
    }

    // get count by category
    std::cout<<"\nAvailable vehicle categories: \n1. SUV\t2. HatchBack\t3. Sedan\n\n\nEnter Vehicle category to get count: ";
    int choice;
    getchar();
    std::cin>>choice;
    try {
        Car *c =  dynamic_cast<Car*>(cars);
        Bike *b = dynamic_cast<Bike*>(bikes);
        std::cout<<"\n\nCount of vehicles of category is "<<getCountOnCategory(choice, c, b)<<"\n\n";
    } catch(VehicleNotFoundException ex) {
        std::cout<<"\n"<<ex.what();
    }

    // get average by category
    std::cout<<"\nAvailable vehicle categories: \n4. Commute\t5. Sports\t6. Offreader\n\nEnter Vehicle category to get average: ";
    int choice1;
    // getchar();
    std::cin>>choice1;
    try {
        Car *c =  dynamic_cast<Car*>(cars);
        Bike *b = dynamic_cast<Bike*>(bikes);
        std::cout<<"\n\nAverage price of vehicles of category is "<<getAvgOfvehicle(choice1, c, b)<<"\n\n";
    } catch(VehicleNotFoundException ex) {
        std::cout<<"\n"<<ex.what();
    }

    delete []cars;
    delete []bikes;
    return 0;
}



// raw code

/*
// // get data for SUV
    // Vehicle* carSuv = new Car();
    // std::cin>>carSuv;

    // // get data for HatchBack
    // Vehicle* carHB = new Car();
    // std::cin>>carHB;

    // // get data for Sedan
    // Vehicle* carSedan = new Car();
    // std::cin>>carSedan;

    // // get data for Commute
    // Vehicle* bikeCommute = new Bike();
    // std::cin>>bikeCommute;

    // // get data for sports
    // Vehicle* bikeSports = new Bike();
    // std::cin>>bikeSports;

    // // get data for offroader
    // Vehicle* bikeOffroad = new Bike();
    // std::cin>>bikeOffroad;

    // carSuv->display();

    // delete carSuv;
    // delete carHB;
    // delete carSedan;
    // delete bikeCommute;
    // delete bikeOffroad;
    // delete bikeSports;

    enum CarCategory {
    SUV , HatchBack, Sedan

    public:
        // enum Category {SUV = 1, HatchBack = 2, Sedan = 3, Commute = 4, Sports = 5, Offroad = 6};
    
}
*/