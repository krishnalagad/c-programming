#include <iostream>

class Base {
    private:
        int field1;
        int field2;
    public:
        Base(): field1(0), field2(0) { std::cout<<"\nBase() called!!"; }
        Base(int f1, int f2): field1(f1), field2(f2) { std::cout<<"\nBase(...) called!!"; }
        virtual ~Base() { std::cout<<"\n~Base called!!"; }

        virtual void show() { std::cout<<"\nf1: "<<field1<<"\nf2: "<<field2<<"\n"; }

        int getField1() const { return field1; }
        void setField1(int field1_) { field1 = field1_; }
        int getField2() const { return field2; }
        void setField2(int field2_) { field2 = field2_; }        
};

class Derived: public Base {
    private:
        int field3;
        int field4;
    public:
        Derived(): field3(0), field4(0) { std::cout<<"\nDerived() called!!"; }
        Derived(int f3, int f4, int f1, int f2): field3(f3), field4(f4) { 
            Base::setField1(f1);
            Base::setField2(f2);
            std::cout<<"\nDerived() called!!"; 
        }
        ~Derived() { std::cout<<"\n~Derived() called!!"; }

        void show() { 
            Base::show();
            std::cout<<"\nf3: "<<field3<<"\nf4: "<<field4<<"\n"; 
        }

        int getField3() const { return field3; }
        void setField3(int field3_) { field3 = field3_; }
        int getField4() const { return field4; }
        void setField4(int field4_) { field4 = field4_; }
        
};
int main(void) {
    Derived d;
    d.show();

    Base* basePtr = new Derived(12,23,34,45);
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        derivedPtr->show();
    } else {
        // Cast failed, basePtr does not point to a Derived object
    }

    Derived* derivedPtr1 = new Derived(12,23,34,45);
    Base* basePtr1 = dynamic_cast<Base*>(derivedPtr1);
    basePtr1->show();

    delete basePtr, derivedPtr1;
    return 0;
}