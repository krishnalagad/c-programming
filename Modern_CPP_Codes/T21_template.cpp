#define TEMPLATE

#include <iostream>
#include <typeinfo>

#ifdef TEMPLATE
template <typename T>
T getMax(const T &a, const T &b) {
    return a > b ? a : b;
}
#else
int getMax(const int &a, const int &b) {
    return a > b ? a : b;
}
#endif

int main() {
    std::cout<<"\n"<<getMax(12, 56)<<"\n";
    // std::cout<<"\n"<<typeid(12)<<"\n";
}