/*
    100 times withdraw 10 Rs.
    100 times deposit 10 Rs.
*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mt;

void withdraw(int& amount) {
    for (int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount -= 10;
        mt.unlock();
    }
    // std::cout << "Amount after withdrawal: " << amount <<std::endl;
}

void deposit(int& amount) {
    for (int i = 0; i < 100; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        mt.lock();
        amount += 10;
        mt.unlock();
    }
    // std::cout << "Amount after deposit: " << amount <<std::endl;
}

// g++ thread_demo2.cpp -lpthread -o app && time ./app && rm app
// for((i = 0; i < 50; i++)); do ./app; done;

int main() {
    int amount = 1000;
    // withdraw(amount);
    // deposit(amount);

    std::thread t1(withdraw, std::ref(amount));
    std::thread t2(deposit, std::ref(amount));

    t1.join();
    t2.join();

    std::cout << "Amount is: " << amount << std::endl;

    return 0;
}