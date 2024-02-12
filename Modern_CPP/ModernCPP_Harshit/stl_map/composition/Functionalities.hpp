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

#endif // FUNCTIONALITIES_HPP
