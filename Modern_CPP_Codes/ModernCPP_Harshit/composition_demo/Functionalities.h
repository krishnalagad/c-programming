#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>
#include "BankAccount.h"

using BankPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<BankPointer>;

void createObjects(Container& data);    // empty container
void display(Container& data);

#endif // FUNCTIONALITIES_H
