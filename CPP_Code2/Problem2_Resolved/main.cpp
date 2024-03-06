#include <iostream>
#include "car.h"
#include "bike.h"

// Implement the global functions for functionalities here

// Function to get vehicle by chassis number
void getVehicleByChassisNumber(int no, Vehicle* vehicles) {
    bool flag = false;
    for (int i = 0; i < 3; i++) {
        if (no == vehicles[i].getChassisNumber()) {
            vehicles[i].display();
            flag = true;
        }
    }

    if (!flag)
        std::cout << "Vehicle not found with given chassis number\n";
}

// Function to get total count of vehicles by category
int getCountOnCategory(int cat, Vehicle* vehicles) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        // Assuming category is stored as an integer in the base class
        if (cat == vehicles[i].getExPrice()) {
            count += 1;
        }
    }

    return count;
}

// Function to get average of price of vehicle for the specific category
double getAvgOfvehicle(int cat, Vehicle* vehicles) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        // Assuming category is stored as an integer in the base class
        if (cat == vehicles[i].getExPrice()) {
            sum += vehicles[i].getExPrice();
            count += 1;
        }
    }

    if (count == 0) {
        std::cout << "No vehicles found in the given category\n";
        return 0.0;
    }

    return sum / count;
}

int main() {
    // Create arrays for Car and Bike
    Car cars[3];
    Bike bikes[3];

    // Initialize Car array
    cars[0] = Car(1001, "Toyota", 25000.0, 10.0, 500.0, SUV);
    cars[1] = Car(1002, "Honda", 22000.0, 9.5, 450.0, HatchBack);
    cars[2] = Car(1003, "Ford", 27000.0, 11.0, 550.0, Sedan);

    // Initialize Bike array
    bikes[0] = Bike(2001, "Hero", 12000.0, 5.0, 300.0, Commute);
    bikes[1] = Bike(2002, "Ducati", 18000.0, 7.5, 400.0, Sports);
    bikes[2] = Bike(2003, "KTM", 15000.0, 6.5, 350.0, Offroader);

    // Use base class pointer to access functionalities
    Vehicle* vehiclePtr;

    // Example 1: Get vehicle by chassis number
    int chassisToFind = 1002;
    vehiclePtr = cars; // Assigning the array to the base class pointer

    getVehicleByChassisNumber(chassisToFind, vehiclePtr);

    // Example 2: Get total count of vehicles by category
    int categoryToCount = 22000.0;
    int count = getCountOnCategory(categoryToCount, vehiclePtr);
    std::cout << "Count of vehicles in the given category: " << count << "\n";

    // Example 3: Get average of price of vehicle for the specific category
    int categoryToAverage = 25000.0;
    double average = getAvgOfvehicle(categoryToAverage, vehiclePtr);
    std::cout << "Average price of vehicles in the given category: " << average << "\n";

    return 0;
}
