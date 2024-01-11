#include <iostream>
#include <typeinfo>

template<class T1, class T2>
T1 getMaxT(T1 a, T2 b) {
    return a > b ? a : b;
}

auto getMax(auto a, auto b) {
    return a > b ? a : b;
}

int main() {
    auto a = 5;
    const auto b = 8;
    const auto c = 5.5;
    auto d = 5.5f;
    auto pa = &a;
    auto pb = &b;
    const auto pc = &c;

    auto ptr1 = new int;    // ptr to int
    auto ptr2 = new int[5]; // ptr to int
    auto ptr3 = new int[5][4];  // ptr to array of 4 int

    std::cout<<"Type of a: "<<typeid(a).name()<<std::endl;
    std::cout<<"Type of const b: "<<typeid(b).name()<<std::endl;
    std::cout<<"Type of c: "<<typeid(c).name()<<std::endl;
    std::cout<<"Type of d: "<<typeid(d).name()<<std::endl;
    std::cout<<"Type of pa: "<<typeid(pa).name()<<std::endl;
    std::cout<<"Type of pb: "<<typeid(pb).name()<<std::endl;
    std::cout<<"Type of pc: "<<typeid(pc).name()<<std::endl;

    std::cout<<"Type of ptr1: "<<typeid(ptr1).name()<<std::endl;
    std::cout<<"Type of ptr2: "<<typeid(ptr2).name()<<std::endl;
    std::cout<<"Type of ptr3: "<<typeid(ptr3).name()<<std::endl;

    std::cout<<"Max element: "<<getMaxT(12, 23.4f)<<std::endl;

    delete ptr1;
    delete []ptr2;
    delete []ptr3;
    return 0;
}
