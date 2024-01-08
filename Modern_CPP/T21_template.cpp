#define TEMPLATE

#include <iostream>

#ifdef TEMPLATE
template <typename T>
T getMax(const T &a, const T &b) {
    return a > b ? a : b;
}
#else
int getMax(int &a, int &b) {
    return a > b ? a : b;
}
#endif

int main() {
    std::cout<<"\n"<<getMax(12, 56)<<"\n";
}