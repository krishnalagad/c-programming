#include <iostream>
#include <vector>
#include <future>

float averageOfNValues(std::future<int>& ft) {
    std::vector<int> data {10, 20, 30, 40, 50};

    int N = ft.get();
    if (data.size() < N || N < 0)
        throw std::runtime_error("Invalid operation!!\n");
    
    float ans = 0.0f;
    int count = 0;

    for (auto itr = data.begin(); count < N; count++) {
        ans += *itr;
        itr++;
    }

    return ans / N;
}

/*
    g++ async_demo1.cpp -lpthread -g -o app && ./app && rm app
*/
int main() {
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<float> result = std::async(std::launch::async, averageOfNValues, std::ref(ft));

    int n;
    std::cin >> n;

    pr.set_value(n);

    std::cout << "Average: " << result.get() << std::endl;

    return 0;
}