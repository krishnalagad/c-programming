#include <iostream>

template<typename T>
T add(T n1) {
    return n1;
}

template<typename T, typename... Args>
T add(T n1, Args... args) {
    return n1 + add(args...);
}
/*
    g++ variadic_template.cpp -g -o app && time ./app && rm app
*/
int main() {
    std::cout << "Addition is: " << add(10, 20, 30, 40, 50) << std::endl;

    return 0;
}