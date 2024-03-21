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
/*
    g++ rvalue_reference.cpp -o app && time ./app && rm app
*/
int main() {
    std::string str = "Krishna";
    destination(str);
    destination(std::move(str));
    destination(std::ref(str));
    destination("Krishna");

    return 0;
}