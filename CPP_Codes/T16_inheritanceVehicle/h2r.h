#ifndef H2R_H
#define H2R_H

#include <iostream>
#include "bike.h"

class H2R: public Bike {
    private:
        int price;
    public:
        H2R(): price(400) { std::cout<<"\nH2R() called!!"; }
        H2R(int price, int speed, int engine, int seats): price(price) { 
            setEngine(engine);
            setSeats(seats);
            setSpeed(speed);
            std::cout<<"\nH2R() called!!";
        }
        ~H2R() { std::cout<<"\n~H2R() called!!\n"; }

        void start() { std::cout<<"\nH2R started!!"; }
        void stop() { std::cout<<"\nH2R stopped!!"; }
        void show() {
            Bike::show();
            std::cout<<"\nPrice: "<<this->price;
        }

        int getPrice() const { return price; }
        void setPrice(int price_) { price = price_; }
};

#endif // H2R_H
