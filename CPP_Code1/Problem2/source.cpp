#include <iostream>
#include <cstring>
#include "bank.h"

static int idGenerater = 219300;

Loan::Loan(){
    this->loanNumber = idGenerater++;
    this->amount = 110.0f;
    strcpy(this->name, "DEFAULT");
    this->interestAmt = 130.0f;
}

Loan::Loan(float amount, char *name, float interestAmt){
    this->loanNumber = idGenerater++;
    this->amount = amount;
    strcpy(this->name, name);
    this->interestAmt = interestAmt;
}

Loan::~Loan(){

}

Loan Loan::insertRecord() {
    this->loanNumber = idGenerater++;

    std::cout<<"Enter amount: ";
    std::cin>>this->amount; 

    float temp = calculateInterestAmount(this->amount);
    this->interestAmt = temp;

    getchar();
    std::cout<<"Enter Name: ";
    std::cin.getline(this->name, 50);

    Loan loan = *this;
    return loan;
}

float Loan::calculateInterestAmount(float amount) {
    float interestAmt = 0;
    if (amount <= 100000) {
        interestAmt = amount * 0.02f;
        return interestAmt;
    } else if (amount > 100000 && amount <= 500000) {
        interestAmt = amount * 0.05f;
        return interestAmt;
    } else if (amount > 500000 && amount <= 1500000) {
        interestAmt = amount * 0.1f;
        return interestAmt;
    } else {
        interestAmt = amount * 0.2f;
        return interestAmt;
    }
}