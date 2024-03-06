#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle {
private:
    int chassisNumber;
    std::string vehicleBrand;
    double exPrice;
    float tax;
    double insuranceAmt;

public:
    Vehicle();
    Vehicle(int chassis, const std::string& brand, double price, float tax, double insurance);
    ~Vehicle();

    int getChassisNumber() const;
    std::string getVehicleBrand() const;
    double getExPrice() const;
    float getTax() const;
    double getInsuranceAmt() const;

    void setChassisNumber(int chassis);
    void setVehicleBrand(const std::string& brand);
    void setExPrice(double price);
    void setTax(float tax);
    void setInsuranceAmt(double insurance);

    void display() const;
};

#endif // VEHICLE_H
