#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include "Demo.hpp"

unsigned int getNumber(int param) {
    return param;
}

void pattern() {
    for (long i = 1; i <= 100; i++) {
        if (i % 2 == 0) 
            std::cout << "\n\nIfPart: " << i << " --> SQUARE --> " << i * i << "" << std::endl;
        else {
            std::cout << "\nElsePart: " << i << "\n";
            int temp = 0;
            for (long j = 1; j <= i; j++) {
                if (temp > 4) {
                    temp = 0;
                    std::cout << std::endl;
                }
                std::cout << j << " --> CUBE --> " << j * j * j << " |" << " ";
                temp += 1;
            }  
        }
    }
}

void practice() {
    using DemoPointer = std::shared_ptr<Demo>;
    using DemoPointerContainer = std::vector<DemoPointer>;

    DemoPointerContainer data = {
        {std::make_shared<Demo>("Krishna Lagad", 101, 23.2f)},
        {std::make_shared<Demo>("Varsha Lagad", 102, 29.2f)},
        {std::make_shared<Demo>("Geeta Lagad", 103, 34.2f)},
    };

    for (const DemoPointer& ptr: data) {
        std::cout << *ptr << std::endl;
    }
}
/*
    g++ practice.cpp -lpthread -o app && time ./app > output.txt && cat output.txt && rm app && rm output.txt
    g++ practice.cpp -lpthread -o app && time ./app && rm app
    gcc practice.c -o app && time ./app && rm app
*/
int main(int argc, char const *argv[]) {
    // register int a = 10;
    // std::cout << "register a val: " << a << std::endl;
    // std::cout << "register a add: " << &a << std::endl;

    // std::thread t1(pattern);
    // if (t1.joinable())
    //     t1.join();

    // std::cout << getNumber(-230) << std::endl;

    practice();

    return 0;
}