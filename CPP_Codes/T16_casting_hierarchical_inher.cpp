#include <iostream>

class Base {
    public:
        virtual ~Base() {}
};

class Derived1 : public Base {
    public:
        void derived1Method() {
            std::cout<<"Derived method of Derived1 class!!\n";
        }
};

class Derived2 : public Base {
    public:
        void derived2Method() {
            std::cout<<"Derived method of Derived2 class!!\n";
        }
};

int main() {
    Base* basePtr1 = new Derived1();
    Base* basePtr2 = new Derived2();

    // static_cast may be used for downcasting in hierarchical inheritance
    Derived1* derived1Ptr = static_cast<Derived1*>(basePtr1);
    derived1Ptr->derived1Method();

    // dynamic_cast is preferred for downcasting in hierarchical inheritance
    Derived2* derived2Ptr = dynamic_cast<Derived2*>(basePtr2);
    derived2Ptr->derived2Method();

    delete basePtr1;
    delete basePtr2;

    return 0;
}
