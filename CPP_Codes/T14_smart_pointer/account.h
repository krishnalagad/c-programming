#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>

static int accNumberGenerator = 219304000;

class BankAccount {
    private:
        int bankId;
        float currAmount;
        std::string accHolderName;
    public:
        BankAccount(): bankId(++accNumberGenerator), currAmount(30833.23), accHolderName("Krishna Lagad") {}
        BankAccount(float amt, std::string name): bankId(++accNumberGenerator), currAmount(amt), accHolderName(name){}
        void show() {
            std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
            std::cout<<"\nAccount Number: "<<this->bankId<<"\nAccount holder name: "<<accHolderName;
            std::cout<<"\nCurrent Balance: "<<this->currAmount<<std::endl;
        }
};

#endif // ACCOUNT_H
