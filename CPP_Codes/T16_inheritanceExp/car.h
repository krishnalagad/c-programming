#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "vehicle.h"

class Car: public Vehicle {
    private:
        int gear;
    public:
        Car(): gear(6) { std::cout<<"\nCar() called!!";}
        Car(int gear, int speed): gear(gear) {
            Vehicle::setSpeed(speed);
            std::cout<<"\nCar(...) called!!";
        }
        ~Car() { std::cout<<"\n~Car() called!!\n";}

        void start() { std::cout<<"\nCar started!!"; }
        void stop() { std::cout<<"\nCar stopped!!"; }
        void show() { 
            Vehicle::show();
            std::cout<<"\nGear: "<<this->gear; 
        }

        int getGear() { return gear; }
        void setGear(int gear_) { gear = gear_; }
};

#endif // CAR_H
