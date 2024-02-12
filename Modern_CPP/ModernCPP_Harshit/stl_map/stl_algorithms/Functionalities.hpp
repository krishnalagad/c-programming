#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <unordered_map>
#include <optional>
#include <algorithm>
#include <numeric>
#include <memory>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using MapContainer = std::unordered_map<unsigned long, AccountPointer>;

void createObjects(MapContainer& data);

#endif // FUNCTIONALITIES_HPP
