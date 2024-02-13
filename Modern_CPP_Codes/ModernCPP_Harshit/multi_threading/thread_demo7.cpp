#include <thread>
#include <array>
#include <iostream>
#include <algorithm>

/*
    step 1: check const & reference to what type?
        std::array<int, 2>
    step 2: look at the class for this type, is it
    copy constructible, move constructible or both?
    step 3: if only move is enabled, user must use lvalue
            if only move is enabled, copy is not allowed, only rvalue
            if both are available, user can pass both lvalue of array or rvalue of array
*/
void Square(const std::array<int, 5>& data) {
    std::for_each(data.begin(), data.end(),
        [](const int& number) {
            std::cout << number * number << "\t";
        }
    );
}

/*
    g++ thread_demo7.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    std::cout << "Hello \n";

    std::array<int, 5> result;
    std::array<int, 5> data {1, 2, 3, 4, 5};
    int i = 0;
    std::thread t1(Square, std::ref(data));

    std::for_each(data.begin(), data.end(),
        [&](const int& number) {
            result[i++] = number * number * number;
        }
    );

    t1.join();

    std::for_each(data.begin(), data.end(),
        [&](const int& number) {
            result[i++] = number * number * number;
        }
    );

    return 0;
}