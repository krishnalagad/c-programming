#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include <array>
#include "BankLoan.h"

using LoanPointer = std::shared_ptr<BankLoan>;
using LoanPointerContainer = std::vector<LoanPointer>;

void createObjects(LoanPointerContainer& data);
void averageLoanAmount(const LoanPointerContainer& data);
std::array<int, 4> valueCount(const LoanPointerContainer& data);
void highestInterestRateForAcceptedLoans(const LoanPointerContainer& data);
LoanPointerContainer getContainerMatchesConditions(const LoanPointerContainer& data);
float getContainerMatchesIntent(const LoanPointerContainer& data, LoanIntent intent);
void getMinMaxAge(const LoanPointerContainer& data);

#endif // FUNCTIONALITIES_H
