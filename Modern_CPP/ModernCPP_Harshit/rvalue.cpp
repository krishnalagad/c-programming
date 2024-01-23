#include <iostream>
#include <vector>

int f1(int n1) { return 0; }

int f2(const int& n1) { return 0; }

int f3(int&& n1) { return 0; }

// takes rvalue ref to std vector of int and returns int by val
int f4(std::vector<int>&& data) { return 0; }

int main() {

    std::vector<int> v1 {10, 20, 30};
    int n1 = 10;
    f1(10);
    f1(n1);
    f3(10); // cant pass var here
    f4(std::move(v1));   // std::move() converts a value to rvalue
    v1.push_back(40);    // any operation after std::move() is illegal, though it works.
    for(int ele: v1) 
        std::cout<<ele<<std::endl;
    return 0;
}