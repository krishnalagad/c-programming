#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include "AccountType.h"

class BankAccount {
    private:
        static int _counter;
        const unsigned long _accountNumber;
        std::string _accountHolderName;
        AccountType _accountType;
        float _accountbalance;

    public:
        BankAccount() = delete;
        BankAccount(const BankAccount&) = delete;
        BankAccount& operator=(const BankAccount&) = delete;
        BankAccount(BankAccount&&) = delete;
        BankAccount& operator=(BankAccount&&) = delete;
        ~BankAccount() = default;

        void depositAmount(long amount);
        void withdrawAmount(long amount);

        unsigned long accountNumber() const { return _accountNumber; }
        std::string accountHolderName() const { return _accountHolderName; }
        void setAccountHolderName(const std::string &accountHolderName) { _accountHolderName = accountHolderName; }
        AccountType accountType() const { return _accountType; }
        void setAccountType(const AccountType &accountType) { _accountType = accountType; }
        float accountbalance() const { return _accountbalance; }       
};

int BankAccount::_counter = 9000000;

#endif // BANKACCOUNT_H
