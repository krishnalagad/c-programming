#include <iostream>
#include <limits>
#include "BankAccount.h"

BankAccount::BankAccount(std::string accountHolderName, AccountType accountType, float acountBalance)
    : _accountNumber(++_counter), _accountHolderName(accountHolderName), _accountType(accountType), 
      _accountBalance(acountBalance) {}

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