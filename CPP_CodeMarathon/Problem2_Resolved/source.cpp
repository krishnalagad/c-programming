#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "bike.h"

static int chassisGenerator = 219300;

// ------------- Vehicle class data-------------

// Constructors and destructor
Vehicle::Vehicle(): chassisNumber(chassisGenerator++), vehicleBrand("DEFAULT"), exPrice(2300000), tax(17.5), insuranceAmt(5000) {}
Vehicle::Vehicle(std::string brand, double price, float tax, double amt): chassisNumber(chassisGenerator++), vehicleBrand(brand), exPrice(price), tax(tax), insuranceAmt(amt) {}
Vehicle::~Vehicle() {}
void Vehicle::display() {
    std::cout<<"\nChassis Number: "<<chassisNumber<<"\nBrand Name: "<<vehicleBrand;
    std::cout<<"\nEx-Showroom Price: "<<exPrice<<"\nTax: "<<tax<<"\nInsurance Amount: "<<insuranceAmt;
    std::cout<<"\nCategory: ";
    // switch (cat)
    // {
    //     case 1:
    //         std::cout<<"SUV";
    //         break;
    //     case 2:
    //         std::cout<<"HatchBack";
    //         break;
    //     case 3:
    //         std::cout<<"Sedan";
    //         break;
    //     case 4:
    //         std::cout<<"Commute";
    //         break;
    //     case 5:
    //         std::cout<<"Sports";
    //         break;
    //     case 6:
    //         std::cout<<"Offroad";
    //         break;
    
    //     default:
    //         break;
    // }
    std::cout<<"\n";
}

void Vehicle::getVehicleByChassisNumber(int no){
    
}

// ------------- Car class data-------------

// Constructors and destructor
Car::Car(): Vehicle() {}
Car::Car(std::string brand, double price, float tax, double amt): Vehicle(brand, price, tax, amt) {}
Car::~Car() {}
void Car::display() {
    Vehicle::display();
    switch (carCategory)
    {
        case 0:
            std::cout<<"SUV";
            break;
        case 1:
            std::cout<<"HatchBack";
            break;
        case 2:
            std::cout<<"Sedan";
            break;
        
    
        default:
            break;
    }
}

// ------------- Bike class data-------------

// Constructors and destructor
Bike::Bike(): Vehicle() {}
Bike::Bike(std::string brand, double price, float tax, double amt): Vehicle(brand, price, tax, amt) {}
Bike::~Bike() {}
void Bike::display() {
    Vehicle::display();
    switch (bikeCategory)
    {
        case 4:
            std::cout<<"Commute";
            break;
        case 5:
            std::cout<<"Sports";
            break;
        case 6:
            std::cout<<"Offroad";
            break;
        default:
            break;
    }
}