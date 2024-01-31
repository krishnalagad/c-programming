#include <iostream>
#include <array>
#include <vector>
#include <functional>

// void operation (std::array<int, 5>& data, enum class Logic op) {
//     if (op == Logic::SQUARE) {
//         for(int val: data) {
//             std::cout << val * val << "\n";
//         }
//     } else if (op == Logic::CUBE) {
//         for(int val: data) {
//             std::cout << val * val * val << "\n";
//         }
//     } else {
//         // something else..
//     }
// }


using FnType = std::function<int(int)>;
using FnContainer = std::array<FnType, 2>;

/*
    benefit of using lamdba function
*/
void operation (const std::vector<int>& data, FnType fn) {
    for (int val: data) {
        std::cout << fn(val) << std::endl;
    }
}

void operation (const std::vector<int>& data, FnContainer& fns) {
    for (auto& fn: fns) {
        for (int val: data) {
            std::cout << fn(val) << std::endl;
        }
    }
}

// g++ -o app &&./app && rm app
int main() {
    operation(std::vector<int> {12, 13, 14, 15}, [](int num) -> int { return num * num; });

    auto square = [](int num){ return num * num; };
    auto cube = [](int num){ return num * num * num; };
    FnContainer fns = {square, cube};

    operation(std::vector<int> {12, 13, 14, 15}, fns);

    return 0;
}