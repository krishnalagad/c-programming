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
    std::cout << amount * amount << std::endl;
}

/*
    g++ thread_demo6.cpp -lpthread -g -o app && ./app && rm app
*/
int main() {
    std::thread t1(calculateSquare);
    int data {0};
    std::cin >> amount;
    flag = true;
    cv.notify_one();
    t1.join();

    return 0;
}