#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include <optional>
#include "BankAccount.h"

using BankPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<BankPointer>;

using CardPointer = std::shared_ptr<DebitCard>;
using CardContainer = std::vector<CardPointer>;

/*
    create objects of Bank class
*/
void createObjects(Container& data);    // empty container
void display(Container& data);

/* Function signature: takes constant lvalue reference of Container where Container is std 
vector of BankPointer and BankPointer is shared ptr of BankAccount class and returns void 
Description: get the sum of account balance of all the accounts */
float findTotalBankBalance(const Container& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns unsighned integer 
Description: get the count of accounts with balance exceed 50000 */
unsigned int countAbove50000BalanceAccount(const Container& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns boolean value 
Description: check if account has attached Debit card or not. */
bool isAnyAccountWithNoCard(const Container& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns unsigned short
Description: find the CVV Number of account with maximum balance. */
std::optional<unsigned short> findMaxBalanceCvvNumber(const Container& data);

/* Function signature: takes constant lvalue reference of Container where Container is std vector 
of BankPointer and BankPointer is shared ptr of BankAccount class and returns string value
Description: find the expiry of account with min balance */
std::optional<std::string> findMinBalanceExpiry(const Container& data);


CardContainer getDebitCardPointers(const Container& data);
std::optional<CardContainer> getNonNullDebitCardPointers(const Container& data);

std::optional<Container> findMatchingAccount(const Container& data);

#endif // FUNCTIONALITIES_H
