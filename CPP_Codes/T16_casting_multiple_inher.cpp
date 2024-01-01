#include <iostream>

class Base1 {
public:
    virtual ~Base1() {}
};

class Base2 {
public:
    virtual ~Base2() {}
};

class Derived : public Base1, public Base2 {
public:
    void derivedMethod() {
        std::cout<<"Derived Method\n";
    }
};

int main() {
    Base1* base1Ptr = new Derived();

    // static_cast for upcasting in multiple inheritance (may lead to ambiguity)
    Derived* derivedPtr1 = static_cast<Derived*>(base1Ptr);
    derivedPtr1->derivedMethod();

    // dynamic_cast is preferred in multiple inheritance for safety
    Derived* derivedPtr2 = dynamic_cast<Derived*>(base1Ptr);
    if (derivedPtr2)
        derivedPtr2->derivedMethod();
    else    
        // throw exception here.
    
    delete base1Ptr;

    return 0;
}