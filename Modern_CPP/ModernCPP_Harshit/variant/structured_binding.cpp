#include <iostream>
#include <array>

/*
    g++ structured_binding.cpp -o app && time ./app && rm app
*/
int main() {
    auto [age, experience] = std::array<int, 2> {22, 2};
    std::cout << age << " " << experience << std::endl;

    auto [salary, name] = std::pair<int, std::string> {25000, "Krishna"};
    std::cout << salary << " " << name << std::endl;

    return 0;
}