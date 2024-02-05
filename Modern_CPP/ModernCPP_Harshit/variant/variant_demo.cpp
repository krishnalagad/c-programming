#include <variant>
#include <iostream>
#include <array>

/* 
    g++ -std=c++17 variant_demo.cpp -o app && ./app && rm app
        - Variant requires version C++17 !!
*/
int main() {
    std::variant<int, float> v1;
    v1 = 10;
    std::visit([](auto&& val){ std::cout << val << std::endl; }, v1);

    v1 = 10.45f;

    std::array<std::variant<float, int>, 3> data;
    for (std::variant<float, int>& v: data) {
        std::visit([](auto&& val){ std::cout << val << std::endl; }, v);
    }

    return 0;
}