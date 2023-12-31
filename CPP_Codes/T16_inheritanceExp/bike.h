#ifndef BIKE_H
#define BIKE_H

#include <ios>
#include "vehicle.h"

class Bike: public Vehicle {
    private:
    public:
        Bike() { std::cout<<"\nBike() called!!"; }
        ~Bike() { std::cout<<"\n~Bike() called!!\n"; }
        void show() {
            Vehicle::show();
        }
        void start() { std::cout<<"\nBike started!!"; }
        void stop() { std::cout<<"\nBike stopped!!"; }
};

#endif // BIKE_H
