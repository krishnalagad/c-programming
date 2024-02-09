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
    std::cout << amount * amount << std::endl;
}

/*
    g++ thread_demo6.cpp -lpthread -g -o app && ./app && rm app
*/
int main() {
    // step 1: Create and schedule t1 thread.
    std::thread t1(calculateSquare);
    int data {0};
    std::cin >> amount;
    flag = true;
    cv.notify_one();
    t1.join();

    return 0;
}