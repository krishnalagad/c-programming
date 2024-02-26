#include <iostream>

/*
    g++ practice.cpp -o app && time ./app && rm app
    gcc practice.c -o app && time ./app && rm app
*/
int main(int argc, char const *argv[]) {
    register int a = 10;
    std::cout << "register a val: " << a << std::endl;
    std::cout << "register a add: " << &a << std::endl;

    return 0;
}
