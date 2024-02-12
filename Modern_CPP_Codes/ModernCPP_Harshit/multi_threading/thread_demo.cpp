#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using Container = std::vector<int>;

std::mutex mt;

void square(Container& data) {
    for(const int& num: data) {
        // Simulate a time-consuming task by sleeping for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Acquire a lock to ensure thread safety when printing
        mt.lock();
        std::cout << "Square: " << num * num << std::endl;
        // Release the lock to allow other threads to access the critical section
        mt.unlock();
    }
}

void cube(Container& data) {
    for(const int& num: data) {
        // Simulate a time-consuming task by sleeping for 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
        // Acquire a lock to ensure thread safety when printing
        mt.lock();
        std::cout << "Cube: " << num * num * num << std::endl;
        // Release the lock to allow other threads to access the critical section
        mt.unlock();
    }
}


// g++ thread_demo.cpp -lpthread -o app && time ./app && rm app
int main() {
    std::vector<int> data {1, 2, 3};

    // square(data);
    // cube(data);

    // Create two threads, one for the square function and another for the cube function
    std::thread t1(square, std::ref(data));
    std::thread t2(cube, std::ref(data));

    // Main thread waits for t1 to finish execution before moving on
    t1.join();
    // Main thread waits for t2 to finish execution before exiting
    t2.join();
    
    return 0;
}