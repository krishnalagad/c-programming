#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <unordered_map>
#include <optional>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using MapContainer = std::unordered_map<unsigned long, AccountPointer>;
using AccountContainer = std::vector<AccountPointer>;

void createObjects(AccountContainer& accounts, MapContainer& data);

/* Function signature: takes constant lvalue reference of Container where Container is std 
vector of BankPointer and BankPointer is shared ptr of BankAccount class and returns void 
Description: get the sum of account balance of all the accounts */
float findTotalBankBalance(const MapContainer& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns unsighned integer 
Description: get the count of accounts with balance exceed 50000 */
unsigned int countAbove50000BalanceAccount(const MapContainer& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns boolean value 
Description: check if account has attached Debit card or not. */
bool isAnyAccountWithNoCard(const MapContainer& data);

/* Function signature: takes constant lvalue reference of Container & unsigned long value where 
Container is std vector of BankPointer and BankPointer is shared ptr of BankAccount class and 
returns float value Description: find the account balance of the account whose account number is 
provided as a param. */
std::optional<float> findBalanceById(const MapContainer& data, unsigned long accNumber); 

#endif // FUNCTIONALITIES_HPP
