#include <iostream>
#include <cstring>
#include <functional>
/*
    g++ bind.cpp -g -o app && time ./app && rm app
*/
int main() {
    auto strcpy_binded = std::bind(strcpy, std::placeholders::_2, std::placeholders::_1) ;
    char ch[7];
    strcpy_binded("Krishna", ch);

    std::cout << ch <<std::endl;
    
    return 0;
}