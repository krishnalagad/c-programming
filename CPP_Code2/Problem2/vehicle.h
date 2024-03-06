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
        std::string category;
        // Category cat;
    public:
        Vehicle();
        Vehicle(std::string, double, float, double);
        virtual ~Vehicle();
        virtual void display();
        void getVehicleByChassisNumber(int);

        int getChassisNumber() const { return chassisNumber; }
        void setChassisNumber(int chassisNumber_) { chassisNumber = chassisNumber_; }

        std::string getVehicleBrand() const { return vehicleBrand; }
        void setVehicleBrand(const std::string &vehicleBrand_) { vehicleBrand = vehicleBrand_; }

        double getExPrice() const { return exPrice; }
        void setExPrice(double exPrice_) { exPrice = exPrice_; }

        float getTax() const { return tax; }
        void setTax(float tax_) { tax = tax_; }

        double getInsuranceAmt() const { return insuranceAmt; }
        void setInsuranceAmt(double insuranceAmt_) { insuranceAmt = insuranceAmt_; }

        std::string getCategory() const { return category; }
        void setCategory(const std::string &category_) { category = category_; }

        // Category getCat() const { return cat; }
        // void setCat(const Category &cat_) { cat = cat_; }

        friend std::istream& operator>>(std::istream& is, Vehicle& v) {
            std::cout<<"\nEnter brand of vehicle: ";
            is>>v.vehicleBrand;
            std::cout<<"\nEnter Ex-showroom price: ";
            is>>v.exPrice;
            std::cout<<"\nEnter tax (%): ";
            is>>v.tax;
            std::cout<<"\nEnter insurance amount: ";
            is>>v.insuranceAmt;

            return is;
            // std::cout<<"\nAvailable vehicle categories: \n1. SUV\t2. HatchBack\t3. Sedan\n4. Commute\t5. Sports\t6. Offreader\nEnter Vehicle category: ";
            // int choice;
            // is>>choice;

            // switch (choice)
            // {
            //     case 1:
            //         v.cat = SUV;
            //         break;
            //     case 2:
            //         v.cat = HatchBack;
            //         break;
            //     case 3:
            //         v.cat = Sedan;
            //         break;
            //     case 4:
            //         v.cat = Commute;
            //         break;
            //     case 5:
            //         v.cat = Sports;
            //         break;
            //     case 6:
            //         v.cat = Offroad;
            //         break;
                
            //     default:
            //         break;
            // }

            // switch (choice)
            // {
            // case 1:
            //     v.category = "SUV";
            //     break;
            // case 2:
            //     v.category = "HatchBack";
            //     break;
            // case 3:
            //     v.category = "Sedan";
            //     break;
            // case 4:
            //     v.category = "Commute";
            //     break;
            // case 5:
            //     v.category = "Sports";
            //     break;
            // case 6:
            //     v.category = "Offroad";
            //     break;
            
            // default:
            //     break;
            // }
            
        }
};

#endif // VEHICLE_H
