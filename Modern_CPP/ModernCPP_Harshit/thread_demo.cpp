#include <iostream>
#include <thread>
#include <vector>

using Container = std::vector<int>;

void square(Container& data) {
    for(const int& num: data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Square: " << num * num << std::endl;
    }
}

void cube(Container& data) {
    for(const int& num: data) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Cube: " << num * num * num << std::endl;
    }
}

// g++ thread_demo.cpp -o app
int main() {
    std::vector<int> data {1, 2, 3};

    // square(data);
    // cube(data);

    std::thread t1(square, std::ref(data));
    std::thread t2(cube, std::ref(data));

    t1.join();  // main() should wait till t1 finished. Then go to next thread
    t2.join();  // main() will wait for t2 to finish.
    
    return 0;
}