#include <iostream>
#include <limits>
#include "BankAccount.h"

BankAccount::BankAccount(std::string accountHolderName, AccountType accountType, float accountBalance)
    : _accountNumber(++_counter), _accountHolderName(accountHolderName), _accountType(accountType), 
      _accountBalance(accountBalance), _accountDebitCard(nullptr) {}

// delegating construstor
BankAccount::BankAccount(std::string accountHolderName, AccountType accountType, float accountBalance, 
    CardPointer accountDebitCard):  BankAccount(accountHolderName, accountType, accountBalance) {
        _accountDebitCard = accountDebitCard;
}

void BankAccount::depositAmount(long amount) {
    if (_accountBalance + amount > __LONG_MAX__) 
        throw std::runtime_error("Cannot deposit an amount this large!!");
    _accountBalance += amount;
}

void BankAccount::withdrawAmount(long amount) {
    if (amount > _accountBalance) 
        throw std::runtime_error("Cannot deposit an amount this large!!");
    _accountBalance -= amount;
}