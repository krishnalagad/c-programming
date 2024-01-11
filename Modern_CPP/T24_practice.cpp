#include <iostream>
#include <typeinfo>

int main() {
    auto a = 5;
    const auto b = 8;
    const auto c = 5.5;
    auto d = 5.5f;
    auto pa = &a;
    auto pb = &b;
    const auto pc = &c;

    std::cout<<"Type of a: "<<typeid(a).name()<<std::endl;
    std::cout<<"Type of const b: "<<typeid(b).name()<<std::endl;
    std::cout<<"Type of c: "<<typeid(c).name()<<std::endl;
    std::cout<<"Type of d: "<<typeid(d).name()<<std::endl;
    std::cout<<"Type of pa: "<<typeid(pa).name()<<std::endl;
    std::cout<<"Type of pb: "<<typeid(pb).name()<<std::endl;
    std::cout<<"Type of pc: "<<typeid(pc).name()<<std::endl;
    return 0;
}