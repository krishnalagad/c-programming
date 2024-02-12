#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <memory>
#include <ostream>
#include "AccountType.h"
#include "DebitCard.h"

using CardPointer = std::shared_ptr<DebitCard>;

class BankAccount {
    private:
        static int _counter;
        const unsigned long _accountNumber;
        std::string _accountHolderName;
        AccountType _accountType;
        float _accountBalance;
        CardPointer _accountDebitCard;

    public:
        // special functions enable/disable
        BankAccount() = delete;
        BankAccount(const BankAccount&) = delete;
        BankAccount& operator=(const BankAccount&) = delete;
        BankAccount(BankAccount&&) = delete;
        BankAccount& operator=(BankAccount&&) = delete;
        ~BankAccount() { std::cout<<"Bank account destroyed!! "<<_accountNumber<<std::endl; };

        // parameterized constructor for initialization of obj
        BankAccount(std::string, AccountType, float);
        BankAccount(std::string, AccountType, float, CardPointer);

        // member function for account
        void depositAmount(long amount);
        void withdrawAmount(long amount);

        // getters and setters
        unsigned long accountNumber() const { return _accountNumber; }
        std::string accountHolderName() const { return _accountHolderName; }
        void setAccountHolderName(const std::string &accountHolderName) { _accountHolderName = accountHolderName; }
        AccountType accountType() const { return _accountType; }
        void setAccountType(const AccountType &accountType) { _accountType = accountType; }
        float accountbalance() const { return _accountBalance; }  
        CardPointer acccountDebitCard() { return _accountDebitCard; }     

        friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);
};

inline int BankAccount::_counter = 9000000;

#endif // BANKACCOUNT_H
