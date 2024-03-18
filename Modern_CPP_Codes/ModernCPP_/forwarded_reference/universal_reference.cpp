#include <utility>
#include <iostream>
#include <functional>

void destination(const std::string& str) {
    std::cout << "In const lvalue ref fun!! : " << str << std::endl;
}
void destination(std::string& str) {
    std::cout << "In lvalue ref fun!! : " << str << std::endl;
}
void destination(std::string&& str) {
    std::cout << "In rvalue ref fun!! : " << str << std::endl;
}

template<typename T>
void middleware(T&& arg) noexcept {  // noexcept means this function does not throws any exception.
    // T is universal reference: means it can hold the reference of lvalue and rvalue.
    // call to destination function.
    destination(std::forward<T>(arg));
}

/*
    g++ universal_reference.cpp -o app && time ./app && rm app
*/
int main() {
    const std::string str = "Krishna";
    middleware(std::ref(str));
    middleware(std::move(str));
    return 0;
}
