#include "car.h"
#include "bike.h"

// Implement the member functions for Vehicle, Car, and Bike here

Vehicle::Vehicle() : chassisNumber(0), vehicleBrand("DEFAULT"), exPrice(2300000), tax(17.5), insuranceAmt(5000) {}

Vehicle::Vehicle(int chassis, const std::string& brand, double price, float tax, double insurance)
    : chassisNumber(chassis), vehicleBrand(brand), exPrice(price), tax(tax), insuranceAmt(insurance) {}

Vehicle::~Vehicle() {}

int Vehicle::getChassisNumber() const { return chassisNumber; }

std::string Vehicle::getVehicleBrand() const { return vehicleBrand; }

double Vehicle::getExPrice() const { return exPrice; }

float Vehicle::getTax() const { return tax; }

double Vehicle::getInsuranceAmt() const { return insuranceAmt; }

void Vehicle::setChassisNumber(int chassis) { chassisNumber = chassis; }

void Vehicle::setVehicleBrand(const std::string& brand) { vehicleBrand = brand; }

void Vehicle::setExPrice(double price) { exPrice = price; }

void Vehicle::setTax(float tax) { this->tax = tax; }

void Vehicle::setInsuranceAmt(double insurance) { insuranceAmt = insurance; }

void Vehicle::display() const {
    std::cout << "\nChassis Number: " << chassisNumber << "\nBrand Name: " << vehicleBrand;
    std::cout << "\nEx-Showroom Price: " << exPrice << "\nTax: " << tax << "\nInsurance Amount: " << insuranceAmt;

    std::cout << "\n";
}

Car::Car() : Vehicle() {}

Car::Car(int chassis, const std::string& brand, double price, float tax, double insurance, CarCategory cat)
    : Vehicle(chassis, brand, price, tax, insurance), category(cat) {}

Car::~Car() {}

CarCategory Car::getCarCategory() const { return category; }

void Car::setCarCategory(CarCategory cat) { category = cat; }

void Car::display() const {
    Vehicle::display();
    switch (category) {
        case SUV:
            std::cout << "SUV";
            break;
        case HatchBack:
            std::cout << "HatchBack";
            break;
        case Sedan:
            std::cout << "Sedan";
            break;
    }
}

Bike::Bike() : Vehicle() {}

Bike::Bike(int chassis, const std::string& brand, double price, float tax, double insurance, BikeCategory cat)
    : Vehicle(chassis, brand, price, tax, insurance), category(cat) {}

Bike::~Bike() {}

BikeCategory Bike::getBikeCategory() const { return category; }

void Bike::setBikeCategory(BikeCategory cat) { category = cat; }

void Bike::display() const {
    Vehicle::display();
    switch (category) {
        case Commute:
            std::cout << "Commute";
            break;
        case Sports:
            std::cout << "Sports";
            break;
        case Offroader:
            std::cout << "Offroader";
            break;
    }
}
