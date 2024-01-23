#include <iostream>

int f1(int n1) {}

int f2(int& n1) {}

int main() {

    int n1 = 10;
    f1(10);
    f1(n1);
    return 0;
}