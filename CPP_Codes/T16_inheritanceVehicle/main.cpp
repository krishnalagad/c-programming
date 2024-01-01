#include <iostream>
#include "vehicle.h"
#include "car.h"
#include "mclaren.h"
#include "bike.h"
#include "h2r.h"

int main(void) {
    Vehicle v1;
    v1.setSpeed(140);
    v1.setEngine(200);
    v1.setSeats(2);
    v1.start();
    v1.show();
    v1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    Car c1 = Car(7, 30, 240, 600, 4);
    // c1.setSpeed(240);
    c1.start();
    c1.show();
    c1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    McLaren m1 = McLaren(12, 9, 30, 410, 1200, 2);
    // m1.setGear(8);
    // m1.setSpeed(340);
    m1.start();
    m1.show();
    m1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    Bike b1;
    b1.setSpeed(90);
    b1.setEngine(110);
    b1.setSeats(4);
    b1.start();
    b1.show();
    b1.stop();
    std::cout<<"\n";

    std::cout<<"\n";
    H2R h1 = H2R(6700000, 408, 1200, 1);
    h1.start();
    h1.show();
    h1.stop();
    std::cout<<"\n";

    std::cout<<"\n---------------------------\n";
    McLaren* mPtr = new McLaren(12, 9, 30, 410, 1200, 2);   // object slicing
    mPtr->show();
    std::cout<<"\n\n----------Static casting (Upcasting)----------";
    Vehicle* vPtr = static_cast<Vehicle*>(mPtr);
    vPtr->show();

    std::cout<<"\n\n---------------------------\n";
    Vehicle* vPtr1 = new Vehicle(120, 600, 4);
    vPtr1->show();
    std::cout<<"\n\n----------Dynamic casting (downcasting)----------";
    McLaren* mPtr1 = dynamic_cast<McLaren*>(vPtr1);
    if (mPtr1)
        mPtr1->show();
    else    
        std::cout<<"\nDowncast failed!!";
    
    delete mPtr;
    delete vPtr1;

    return 0;
}