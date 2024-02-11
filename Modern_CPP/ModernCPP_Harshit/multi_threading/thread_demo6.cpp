#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

int amount = 0;
std::mutex mt;
std::condition_variable cv;
bool flag = false;

void calculateSquare() {
    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, [](){ return flag; });
    // lk is unlocked. t1 thread goes to sleep
    std::cout << "Square of " << amount << " is " << amount * amount << std::endl;
}

/*
    g++ thread_demo6.cpp -lpthread -g -o app && ./app && rm app
*/
int main() {
    // step 1: Create and schedule t1 thread.
    std::thread t1(calculateSquare);
    int data {0};
    std::cin >> amount;

    std::cout <<"\nEnter you name: ";
    std::string name;
    std::getchar();
    std::getline(std::cin, name);
    std::cout << "Your name is: " << name << std::endl;

    flag = true;
    cv.notify_one();
    t1.join();

    std::cout << "Length of you name is: " << name.length() << std::endl;

    return 0;
}