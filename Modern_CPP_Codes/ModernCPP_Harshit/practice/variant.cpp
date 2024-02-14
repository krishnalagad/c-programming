#include <variant>
#include <array>
#include <iostream>

using VType = std::variant<int, std::string>;
using Container = std::array<VType, 5>;

void operation(const Container& data) {
    for (const VType& v: data) {
        auto fn = [](auto&& val){ std::cout << "Actual Data: " << val << "\n"; };
        std::visit(fn, v);

        // std::cout << "\nOperation on data based on datatype\n";
        if (std::holds_alternative<int>(v)) {
            int num = std::get<0>(v);
            std::cout << "Square of Number: " << num * num << std::endl;
        } else {
            std::string temp = std::get<1>(v);
            std::cout << "Length of String: " << temp.length() << std::endl;
        }
    }
}
/*
    g++ variant.cpp -g -o app && time ./app && rm app
*/
int main() {
    Container data;
    data[0] = 10;
    data[1] = 20;
    data[2] = 50;
    data[3] = "Krishna";
    data[4] = "Lagad";

    operation(data);

    return 0;
}