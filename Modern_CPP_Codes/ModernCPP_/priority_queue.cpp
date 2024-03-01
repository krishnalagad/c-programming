#include <queue>
#include <vector>
#include <iostream>

struct LessEqualComparator {
    bool operator()(int a, int b) {
        return a <= b;
    }
};
/*
    g++ priority_queue.cpp -g -o app && time ./app && rm app
*/
int main() {
    std::vector<int> data {990, 560, 10, 20, 30, 10, 20};
    std::priority_queue<int, std::vector<int>, LessEqualComparator> pq(data.begin(), data.end());

    std::cout << "Now highest priority element: " << pq.top() << std::endl;
    pq.push(120);
    std::cout << "Now highest priority element: " << pq.top() << std::endl;
    pq.push(640);
    std::cout << "Now highest priority element: " << pq.top() << std::endl;
    // pq.pop();
    // std::cout << "Now highest priority element: " << pq.top() << std::endl;
    // pq.pop();
    // std::cout << "Now highest priority element: " << pq.top() << std::endl;
    // pq.pop();
    // std::cout << "Now highest priority element: " << pq.top() << std::endl;

    while (!pq.empty()) {
        std::cout << "Now highest priority element: " << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}