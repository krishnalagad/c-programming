#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "vehicle.h"

class Car: public Vehicle {
    private:
        int gear;
        int ac;
    public:
        Car(): gear(6), ac(28) { std::cout<<"\nCar() called!!";}
        Car(int gear, int ac, int speed, int engine, int seats): gear(gear), ac(ac) {
            Vehicle::setSpeed(speed);
            Vehicle::setEngine(engine);
            Vehicle::setSeats(seats);
            std::cout<<"\nCar(...) called!!";
        }
        ~Car() { std::cout<<"\n~Car() called!!\n";}

        void start() { std::cout<<"\nCar started!!"; }
        void stop() { std::cout<<"\nCar stopped!!"; }
        void show() { 
            Vehicle::show();
            std::cout<<"\nGear: "<<this->gear<<"\nAC: "<<this->ac; 
        }

        int getGear() { return gear; }
        void setGear(int gear_) { gear = gear_; }

        int getAc() const { return ac; }
        void setAc(int ac_) { ac = ac_; }
};

#endif // CAR_H
