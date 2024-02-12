#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <array>

std::mutex mt;

// g++ thread_demo3.cpp -lpthread -o app && time ./app
int main() {
    std::vector<std::vector<int>> inputs {
        std::vector<int>  {10, 20, 30},
        std::vector<int>  {10, 20, 30},
        std::vector<int>  {10, 20, 30}
    };

    auto f1 = [](std::vector<int>& data){ 
        float tot = 0.0f;
        for (int val: data)
            tot += val;
        mt.lock();
        std::cout << "Average is: " << (tot / data.size()) << std::endl;
        mt.unlock();
    };

    std::array<std::thread, 3> arr;

    auto itr = inputs.begin();
    for(std::thread& th: arr) {
        th = std::thread(f1, std::ref(*itr));
        itr++;
    }

    for (std::thread& th: arr) {
        if (th.joinable()) {
            th.join();
        }
    }

    return 0;
}