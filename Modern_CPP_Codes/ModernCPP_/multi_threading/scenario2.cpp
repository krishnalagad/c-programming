/*
    scenario 2: I have two functions to be executed. Both of them are independent of each other. 
            They can be executed simultaneously. They both write to a shared memory.

            for e.g: Main and t1 calculating square and cube of numbers respectively and printing it on the console
            since there is no write to shared memory, use std::thread with a synchronization primitive
*/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex for synchronizing access to shared memory

// Function to calculate square of a number
void calculateSquare(int num) {
    // Simulate some computation
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Acquire lock to access shared resource
    std::lock_guard<std::mutex> lock(mtx);
    
    // Write to shared memory
    std::cout << "Square of " << num << " is " << num * num << std::endl;
}

// Function to calculate cube of a number
void calculateCube(int num) {
    // Simulate some computation
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Acquire lock to access shared resource
    std::lock_guard<std::mutex> lock(mtx);

    // Write to shared memory
    std::cout << "Cube of " << num << " is " << num * num * num << std::endl;
}
/*
    g++ scenario2.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    std::cout << "Main program started." << std::endl;

    // Create threads for calculating square and cube
    int num = 5; // Number for which square and cube need to be calculated
    std::thread t1(calculateSquare, num);
    std::thread t2(calculateCube, num);

    // Wait for threads to finish
    t1.join();
    t2.join();

    std::cout << "Main program finished executing." << std::endl;

    return 0;
}
