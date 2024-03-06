#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Unit.hpp"
#include "Account.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include <algorithm>
#include <map>
#include <optional>
#include <numeric>
#include <memory>

using AccountPointer = std::shared_ptr<Account>;
using AccountPointerMap = std::map<int, AccountPointer>;

/*
    Function takes lvalue reference of AccountPointerMap where AccountPointerMap is std::map
    of integer key and AccountPointer value where Accountpointer is smart pointer of Account
    class and returns void
*/
void createObjects(AccountPointerMap& data);

/*
    Function takes constant lvalue reference of AccountPointerMap, integer account number, string 
    unit number where AccountPointerMap is std::map of integer key and AccountPointer value where 
    Accountpointer is smart pointer of Account class and returns bool
*/
bool addfareAmount(const AccountPointerMap& data, int accountNumber, std::string unitNumber, int amount);

/*
    Function takes constant lvalue reference of AccountPointerMap, integer account number
    where AccountPointerMap is std::map of integer key and AccountPointer value where 
    Accountpointer is smart pointer of Account class and returns integer number
*/
int getTotalRevenueForAccount(const AccountPointerMap& data, int accountNumber);

/*
    Function takes constant lvalue reference of AccountPointerMap, integer account number
    where AccountPointerMap is std::map of integer key and AccountPointer value where 
    Accountpointer is smart pointer of Account class and returns integer number
*/
int getBonusAmountForAccount(const AccountPointerMap& data, int accountNumber);

#endif // FUNCTIONALITIES_HPP
