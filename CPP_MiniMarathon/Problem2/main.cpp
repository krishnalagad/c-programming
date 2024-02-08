#include <iostream>
#include <cstring>
#include "bank.h"

Loan *loan = new Loan[LOAN_SIZE];
static int count = 0;

void add(Loan l) {
    loan[count].setLoanNumber(l.getLoanNumber());
    loan[count].setAmount(l.getAmount());
    loan[count].setName(l.getName());
    loan[count].setInterestAmt(l.getInterestAmt());
    count++;
}

void show() {
    std::cout<<"\n---------------ALL RECORDS-----------------\n";
    for (int i = 0; i < count; i++){
        std::cout<<"\nLoan Number: "<<loan[i].getLoanNumber()<<"\nAmount: "<<loan[i].getAmount()<<"\nName: "<<loan[i].getName()<<"\nInterest Amount: "<<loan[i].getInterestAmt()<<std::endl;
    } 
}

void search() {
    std::cout<<"\n---------------SEARCH RECORD-----------------\n";
    std::cout<<"\nEnter loan number: ";
    int loanNumber;
    std::cin>>loanNumber;
    bool flag = true;
    for (int i = 0; i < count; i++){
        if (loanNumber == loan[i].getLoanNumber()){
            std::cout<<"\nLoan Number: "<<loan[i].getLoanNumber()<<"\nAmount: "<<loan[i].getAmount()<<"\nName: "<<loan[i].getName()<<"\nInterest Amount: "<<loan[i].getInterestAmt()<<std::endl;
            flag = true;
            break;
        } else {
            flag = false;
        }
    } 
    if(!flag)
        std::cout<<"\nRecord not found!!\n";
}

void countCustomers() {
    std::cout<<"\n---------------MAXIMUM INTEREST AMOUNT-----------------\n";
    float max = loan[0].getInterestAmt();
    for (int i = 1; i < count; i++){
       if (loan[i].getInterestAmt() > max){
            max = loan[i].getInterestAmt();
       }
    }
    std::cout<<"\nMaximum interest amount is: "<<max<<std::endl; 
}

int main(void) {
    char ch;
    Loan l1,temp;
    do{
        std::cout<<"\n1. ADD ONE RECORD\n2. SHOW ALL RECORDS\n3. SEARCH RECORD\n4. COUNT CUSTOMERS\n5. EXIT\n";
        std::cout<<"\nEnter your choice: ";
        int choice;
        std::cin>>choice;
        switch (choice)
        {
            case 1:
                temp = l1.insertRecord();
                add(temp);
                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 2:
                show();
                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 3:
                search();
                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 4:
                countCustomers();
                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 5:
                std::cout<<"\nExiting from application\nBye!!\n\n";
                return 0;
            default:
                std::cout<<"\nPlease enter valid choice!!\n";
                break;
        }
    } while (ch == 'y');

    delete []loan;
    return 0;
}