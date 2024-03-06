#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

enum BikeCategory {
    Commute, Sports, Offroader
};

class Bike : public Vehicle {
private:
    BikeCategory category;

public:
    Bike();
    Bike(int chassis, const std::string& brand, double price, float tax, double insurance, BikeCategory cat);
    ~Bike();

    BikeCategory getBikeCategory() const;
    void setBikeCategory(BikeCategory cat);

    void display() const;
};

#endif // BIKE_H
