#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
    private:
        int speed;

    public:
        Vehicle(): speed(0) { std::cout<<"\nVehicle() called!!";}
        Vehicle(int speed): speed(speed) { std::cout<<"\nVehicle(...) called!!\n";}
        virtual ~Vehicle() { std::cout<<"\n~Vehicle() called!!\n"; }

        virtual void start() { std::cout<<"\nVehicle started!!"; }
        virtual void stop() { std::cout<<"\nVehicle stopped!!"; }
        void show() { std::cout<<"\nSpeed: "<<this->speed; }

        int getSpeed() { return speed; }
        void setSpeed(int speed_) { speed = speed_; }
};

#endif // VEHICLE_H
