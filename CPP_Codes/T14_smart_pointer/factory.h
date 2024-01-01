#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include "account.h"

class Factory {
    private:
        BankAccount* b;
    public:
        Factory() { b = new BankAccount(); }
        Factory(float amt, std::string name) { b = new BankAccount(amt, name); }
        ~Factory() { delete b; }
        BankAccount* operator->() { return b; } 
};

#endif // FACTORY_H
