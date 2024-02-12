#include "Functionalities.hpp"
#include "AccountType.h"

void createObjects(MapContainer &data) {
    AccountPointer ptr1 = std::make_shared<BankAccount>(
        "Krishna", AccountType::SAVING, 50000.0f, std::make_shared<DebitCard>(
            109, 1283458736L, "09/12", DebitCardType::RUPAY));

    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(      // make_pair() requires rvalue of its params
            ptr1->accountNumber(), std::move(ptr1)
        )
    );
}