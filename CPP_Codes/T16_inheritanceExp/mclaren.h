#ifndef MCLAREN_H
#define MCLAREN_H

#include <iostream>
#include "car.h"
#include "vehicle.h"

class McLaren: public Car {
    private:
        int airbags;
    public: 
        McLaren(): airbags(8) {std::cout<<"\nMcLaren() called!!";}
        McLaren(int airbags, int gears, int speed): airbags(airbags) {
            setGear(gears);
            setSpeed(speed);
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
