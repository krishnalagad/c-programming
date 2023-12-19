#include <iostream>

class BankAccount{
    int accNo;
    std::string cName;
    double balance;

    public:
        BankAccount(int accNo = 0, std::string name = "Krishna", double balance = 0.0) {
            this->accNo = accNo;
            this->balance = balance;
            this->cName = name;
        }

        void display() {
            std::cout<<"\nAccount No.: "<<this->accNo<<"\nCustomer Name: "<<this->cName<<"\nBalance: "<<this->balance<<std::endl;
        }
};

class Factory{
    BankAccount *b;
    public:
        Factory() {
            b = new BankAccount();
        }
        Factory(int accNo, std::string name, double balance) {
            b = new BankAccount(accNo, name, balance);
        }
        ~Factory() {
            delete b;
        }
        BankAccount* operator ->() {
            return b;
        }
};

int main(void) {
    Factory f1;
    f1->display();
    return 0;
}