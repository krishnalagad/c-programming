#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
    private:
        int speed;
        int engine;
        int seats;

    public:
        Vehicle(): speed(0), engine(0), seats(0) { std::cout<<"\nVehicle() called!!";}
        Vehicle(int speed, int engine, int seats): speed(speed), engine(engine), seats(seats) { 
            std::cout<<"\nVehicle(...) called!!\n";
        }
        virtual ~Vehicle() { std::cout<<"\n~Vehicle() called!!\n"; }

        virtual void start() { std::cout<<"\nVehicle started!!"; }
        virtual void stop() { std::cout<<"\nVehicle stopped!!"; }
        void show() { std::cout<<"\nSpeed: "<<this->speed<<"\nEngine: "<<this->engine<<"\nSeats: "<<this->seats; }

        int getSpeed() { return speed; }
        void setSpeed(int speed_) { speed = speed_; }

        int getEngine() const { return engine; }
        void setEngine(int engine_) { engine = engine_; }

        int getSeats() const { return seats; }
        void setSeats(int seats_) { seats = seats_; }
};

#endif // VEHICLE_H
