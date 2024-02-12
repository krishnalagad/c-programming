#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>

std::mutex mt;

/*
    fill data in container
*/
void fillData(std::vector<std::vector<int>>& inputs) {
    inputs.emplace_back(std::vector<int>  {10, 20, 30});
    inputs.emplace_back(std::vector<int>  {40, 20, 30});
    inputs.emplace_back(std::vector<int>  {10, 20, 50});
}

std::function<void(std::vector<int>& data)> makeFunction() {
    auto f1 = [](std::vector<int>& data) -> void { 
        float tot = 0.0f;
        for (int val: data)
            tot += val;

        mt.lock();
        std::cout << "Average is: " << (tot / data.size()) << std::endl;
        mt.unlock();
    };

    return f1;
}

void mapThreadsToActions(std::vector<std::vector<int>>& inputs, 
                        std::array<std::thread, 3>& arr,
                        std::function<void(std::vector<int>& data)>& fn) {
    auto itr = inputs.begin();
    for(std::thread& th: arr) {
        th = std::thread(fn, std::ref(*itr));
        itr++;
    }
}

void joinThreads(std::array<std::thread, 3>& arr) {
    for (std::thread& th: arr) {
        if (th.joinable()) {
            th.join();
        }
    }
}

// g++ thread_demo4.cpp -lpthread -o app && time ./app && rm app
int main() {
    std::vector<std::vector<int>> inputs;
    std::array<std::thread, 3> arr;

    fillData(inputs);
    auto fn = makeFunction();

    mapThreadsToActions(inputs, arr, fn);
    joinThreads(arr);

    return 0;
}