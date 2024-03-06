#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "vehicle.h"

enum CarCategory {
    SUV , HatchBack, Sedan };

class Car: public Vehicle {
    private:
        CarCategory carCategory;
    public:
        Car();
        Car(std::string brand, double price, float tax, double amt);
        ~Car();

        void display();
        CarCategory getCarCategory() const { return carCategory; }
        void setCarCategory(const CarCategory &carCategory_) { carCategory = carCategory_; }
        friend std::istream& operator >> (std::istream& is, Car& c) {
            is >> static_cast<Vehicle&>(c);
            std::cout<<"\n\n 0 - SUV, 1 - HatchBack, 2 - Sedan\n";
            int ch;
            is>>ch;
            c.setCarCategory(static_cast<CarCategory>(ch));

            return is;
        }
};



#endif // CAR_H