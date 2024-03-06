#ifndef CAR_H
#define CAR_H

#include "vehicle.h"

enum CarCategory {
    SUV, HatchBack, Sedan
};

class Car : public Vehicle {
private:
    CarCategory category;

public:
    Car();
    Car(int chassis, const std::string& brand, double price, float tax, double insurance, CarCategory cat);
    ~Car();

    CarCategory getCarCategory() const;
    void setCarCategory(CarCategory cat);

    void display() const;
};

#endif // CAR_H
