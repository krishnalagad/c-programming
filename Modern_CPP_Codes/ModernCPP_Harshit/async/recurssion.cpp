#include <iostream>

// C++ 11 and C++14 version 
template<typename T>
T add(T n1) {
    return n1;
}

template<typename T, typename... Args>
T add(T n1, Args... args) {
    return n1 + add(args...);
}

/*
    g++ recurssion.cpp -g -o app && time ./app && rm app
*/
int main() {
    int result = add<int>(10, 20, 30);
    std::cout << result << std::endl;

    return 0;
}