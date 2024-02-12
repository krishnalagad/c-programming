#include "Functionalities.hpp"
#include "AccountType.h"

void createObjects(AccountContainer& accounts, MapContainer& data) {
    accounts.emplace_back(std::make_shared<BankAccount>(
        "Krishna", AccountType::SAVING, 50000.0f, std::make_shared<DebitCard>(
            109, 1283458736L, "09/34", DebitCardType::RUPAY)));

    accounts.emplace_back(std::make_shared<BankAccount>(
            "Rohan", AccountType::SAVING, 40500.0f, std::make_shared<DebitCard>(
                111, 389768279L, "09/25", DebitCardType::MASTERCARD)));

    accounts.emplace_back(std::make_shared<BankAccount>(
            "Kaveri", AccountType::CURRENT, 34000.0f, std::make_shared<DebitCard>(
                897, 930284789L, "03/25", DebitCardType::RUPAY)));

    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(      // make_pair() requires rvalue of its params
            accounts[0]->accountNumber(), std::move(accounts[0])
        )
    );
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(      // make_pair() requires rvalue of its params
            accounts[1]->accountNumber(), std::move(accounts[1])
        )
    );
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(      // make_pair() requires rvalue of its params
            accounts[2]->accountNumber(), std::move(accounts[2])
        )
    );
    
}