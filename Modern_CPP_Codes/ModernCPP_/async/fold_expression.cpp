#include <iostream>

// C++ 17 version 
template<typename... T>
auto add(T... n1) {
    return (n1 + ...);
}

/*
    g++ fold_expression.cpp -g -o app 2>>error_log.txt && time ./app && rm app
*/
int main() {
    int result = add<int>(10, 20, 30);
    std::cout << result << std::endl;

    return 0;
}