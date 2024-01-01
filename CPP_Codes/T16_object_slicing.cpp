#include <iostream>

class Base {
    private:
        int baseValue;
    public:
        Base(int base): baseValue(base) {}
        virtual void show() {
            std::cout<<"\nBase Value: "<<this->baseValue<<std::endl;
        }
        int getBaseValue() const { return baseValue; }
        void setBaseValue(int baseValue_) { baseValue = baseValue_; } 
        
};

class Derived: public Base {
    private:
        int derivedValue;
    public:
        Derived(int base, int derived): Base(base), derivedValue(derived) {}
        void show() {
            std::cout<<"\nDerived Value: "<<this->derivedValue<<"\nBase Value: "<<getBaseValue()<<std::endl;
        }
        int getDerivedValue() const { return derivedValue; }
        void setDerivedValue(int derivedValue_) { derivedValue = derivedValue_; }
};

int main() {
    Derived d1(10,20);
    d1.show();

    Base b1 = d1;   // object sclicing in c++
    b1.show();
    return 0;
}