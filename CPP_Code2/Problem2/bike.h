#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include "vehicle.h"

enum BikeCategory {
    Commute, Sports, Offroad };

class Bike: public Vehicle {
private:
    BikeCategory bikeCategory;
public:
    Bike();
    Bike(std::string brand, double price, float tax, double amt);
    ~Bike();

    void display();

    BikeCategory getBikeCategory() const { return bikeCategory; }
    void setBikeCategory(const BikeCategory &bikeCategory_) { bikeCategory = bikeCategory_; }

    friend std::istream& operator >> (std::istream& is, Bike& c) {
            is >> static_cast<Vehicle&>(c);
            std::cout<<"\n\n 0 - Commute, 1 - Sports, 2 - Offroader\n";
            int ch;
            is>>ch;
            c.setBikeCategory(static_cast<BikeCategory>(ch));

            return is;
        }
};




#endif // BIKE_H
