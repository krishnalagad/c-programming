#include <iostream>

class Vehicle {
    private:
        int speed;

    public:
        Vehicle(): speed(0) {std::cout<<"\nVehicle() called!!";}
        Vehicle(int speed): speed(speed) {std::cout<<"\nVehicle(...) called!!\n";}
        virtual ~Vehicle() { std::cout<<"\n~Vehicle() called!!\n"; }

        virtual void start() { std::cout<<"\nVehicle started!!"; }
        virtual void stop() { std::cout<<"\nVehicle stopped!!"; }
        void show() { std::cout<<"\nSpeed: "<<this->speed; }

        int getSpeed() { return speed; }
        void setSpeed(int speed_) { speed = speed_; }
};

class Car: public Vehicle {
    private:
        int gear;
    public:
        Car(): gear(6) { std::cout<<"\nCar() called!!";}
        Car(int gear): gear(gear) {std::cout<<"\nCar(...) called!!";}
        ~Car() { std::cout<<"\n~Car() called!!\n";}

        void start() { std::cout<<"\nCar started!!"; }
        void stop() { std::cout<<"\nCar stopped!!"; }
        void show() { 
            Vehicle::show();
            std::cout<<"\nGear: "<<this->gear; 
        }

        int getGear() { return gear; }
        void setGear(int gear_) { gear = gear_; }
};

class Bike: public Vehicle {

};

class McLaren: public Car {
    private:
        int airbags;
    public: 
        McLaren(): airbags(8) {std::cout<<"\nMcLaren() called!!";}
        McLaren(int airbags, int gears, int speed): airbags(airbags) {
            Car::setGear(gears);
            Car::setSpeed(speed);
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

class H2R: public Bike{

};

int main(void) {
    Vehicle v1;
    v1.setSpeed(140);
    v1.start();
    v1.show();
    v1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    Car c1 = Car(7);
    c1.setSpeed(240);
    c1.start();
    c1.show();
    c1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    McLaren m1 = McLaren(12, 9, 410);
    // m1.setGear(8);
    // m1.setSpeed(340);
    m1.start();
    m1.show();
    m1.stop();
    std::cout<<"\n";
}