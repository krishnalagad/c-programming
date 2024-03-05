#include <iostream>
#include <thread>

void pattern() {
    for (long i = 0; i < 100; i++) {
        if (i % 2 == 0) 
            std::cout << "\n\nIfPart: " << i << " --> SQUARE --> " << i * i << "" << std::endl;
        else {
            std::cout << "\nElsePart: " << i << "\n";
            int temp = 0;
            for (long j = 0; j < 100; j++) {
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
/*
    g++ practice.cpp -lpthread -o app && time ./app > output.txt && cat output.txt && rm app && rm output.txt
    g++ practice.cpp -lpthread -o app && time ./app && rm app
    gcc practice.c -o app && time ./app && rm app
*/
int main(int argc, char const *argv[]) {
    // register int a = 10;
    // std::cout << "register a val: " << a << std::endl;
    // std::cout << "register a add: " << &a << std::endl;

    std::thread t1(pattern);
    if (t1.joinable())
        t1.join();

    return 0;
}