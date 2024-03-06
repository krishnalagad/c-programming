#include <iostream>
#include <cstring>
#define LOAN_SIZE 100

class Loan
{
    private:
        long int loanNumber;
        float amount;
        char name[50];
        float interestAmt;

    public:
        Loan();
        Loan(float, char *, float);
        ~Loan();
        float calculateInterestAmount(float);
        Loan insertRecord();

        long int getLoanNumber() { return loanNumber; }
        void setLoanNumber(long int loanNumber_) { loanNumber = loanNumber_; }

        float getAmount()  { return amount; }
        void setAmount(float amount_) { amount = amount_; }

        char* getName()  { return name; }
        void setName(char *name_) { strcpy(this->name, name_); }

        float getInterestAmt()  { return interestAmt; }
        void setInterestAmt(float interestAmt_) { interestAmt = interestAmt_; }
};


