#include <iostream>
#include "ThreadHandler.hpp"
/*
    g++ Main.cpp ThreadHandler.cpp -lpthread -o app && time ./app && rm app
*/
int main() {
    int n {0};
    std::cout << "Enter the size of n: ";
    std::cin >> n;

    ThreadHandler obj(n);

    std::thread t1(&ThreadHandler::inputCapture, &obj);
    std::thread t2(&ThreadHandler::operation, &obj);

    if (t1.joinable())
        t1.join();
    if (t2.joinable())
        t2.join();

    obj.printData();

    return 0;
}