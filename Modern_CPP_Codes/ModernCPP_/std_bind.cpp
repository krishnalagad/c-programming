#include <iostream>
#include <functional>
#include <cstring>

int formula(int x, int y, int z) {
    return ((x + y) - z);
}

// g++ std_bind.cpp -o app && ./app && rm app
int main() {
    std::cout << formula(10, 20, 40) << std::endl;

    auto fn = std::bind(formula, std::placeholders::_1, std::placeholders::_2, 10);
    std::cout << fn(10, 20) << std::endl;
    std::cout << fn(10, 20, 30, 40, 50, 60) << std::endl;

    auto bindedStrcpy = std::bind(strcpy, std::placeholders::_2, std::placeholders::_1);
    return 0;
}