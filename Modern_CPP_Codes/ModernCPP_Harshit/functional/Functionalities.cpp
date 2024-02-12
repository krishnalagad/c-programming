#include "Functionalities.hpp"
#include <numeric>

void makeLambda(FnContainer& fns) {
    /*
        find the first number from vector
    */
    auto f1  = [](std::vector<int>& data) -> int {
        if (data.empty()) {
            throw std::runtime_error("Data container is empty!!\n");
        }
        return data.front();
    };

    /*
        find the last number from vector
    */
    auto f2  = [](std::vector<int>& data) -> int {
        if (data.empty()) {
            throw std::runtime_error("Data container is empty!!\n");
        }
        return data.back();
    };
    /*
        find the total
    */
    auto f3  = [](std::vector<int>& data) -> int {
        if (data.empty()) {
            throw std::runtime_error("Data container is empty!!\n");
        }
        int tot = 0;
        return std::accumulate(data.begin(), data.end(), tot);
    };
    fns.emplace_back(f1);
    fns.emplace_back(f2);
    fns.emplace_back(f3);
}

void operation(FnContainer& fns, DataContainer& data) {
    for (const FnType& fn: fns) {
        std::cout << fn(data) << std::endl;
    }
}