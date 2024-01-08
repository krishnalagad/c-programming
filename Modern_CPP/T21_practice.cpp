// #include "iostream"      // this is allowed, but not a good practice
#include <iostream>

extern const int a;   // Only declaration
int b = 2;  // declaration and definition

int main() {
    b = 20;
    std::cout<<"\nextern a : "<<a<<"\nb: "<<b<<std::endl;
    return 0;
}

// int a;
static int myFun(int a, int b) { return 0; }