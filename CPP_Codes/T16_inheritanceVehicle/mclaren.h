#ifndef MCLAREN_H
#define MCLAREN_H

#include <iostream>
#include "car.h"

class McLaren: public Car {
    private:
        int airbags;
    public: 
        McLaren(): airbags(8) {std::cout<<"\nMcLaren() called!!";}
        McLaren(int airbags, int gears, int ac, int speed, int engine, int seats): airbags(airbags) {
            setGear(gears);
            setAc(ac);
            setSpeed(speed);
            setEngine(engine);
            setSeats(seats);
            std::cout<<"\nMcLaren(...) called!!";
        }
        ~McLaren() { std::cout<<"\n~McLaren() called!!\n"; }

        void start() { std::cout<<"\nMcLaren started!!"; }
        void stop() { std::cout<<"\nMcLaren stopped!!"; }
        void show() {
            Car::show();
            std::cout<<"\nAirbags: "<<this->airbags; 
        }

        int getAirbags() { return airbags; }
        void setAirbags(int airbags_) { airbags = airbags_; }
};

#endif // MCLAREN_H
