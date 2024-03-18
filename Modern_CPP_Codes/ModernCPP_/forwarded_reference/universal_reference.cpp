#include <utility>
#include <iostream>

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
void middleware(T&& arg) {  
    // T is universal reference: means it can hold the reference of lvalue and rvalue
    // call to destination function
    destination(std::forward<T>(arg));
}

/*
    g++ universal_reference.cpp -o app && time ./app && rm app
*/
int main() {
    const std::string str = "Krishna";
    middleware(str);
    return 0;
}
