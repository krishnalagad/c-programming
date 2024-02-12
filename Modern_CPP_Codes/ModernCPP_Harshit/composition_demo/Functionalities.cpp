#include "Functionalities.h"

void createObjects(Container &data) {
    data.push_back(
        std::make_shared<BankAccount>(
            "Krishna",
            AccountType::SAVING,
            9087.09f,
            std::make_shared<DebitCard>(
                000,
                11234124512L,
                std::move("12/29"),
                DebitCardType::RUPAY)));

    data.push_back(
        std::make_shared<BankAccount>(
            "Aakanksha",
            AccountType::SAVING,
            8097.09f,
            std::make_shared<DebitCard>(
                675,
                9876123456L,
                std::move("11/30"),
                DebitCardType::VISA)));
}

void display(Container& data) {
    for(BankPointer bPtr: data) {
        std::cout << "Acc Number: " << bPtr->accountNumber() << std::endl;
        std::cout << "Acc Holder: " << bPtr->accountHolderName() << std::endl;
        std::cout << "Acc Balance: " << bPtr->accountbalance() << std::endl;
        std::cout << "Card Number: " << bPtr->acccountDebitCard()->cardNumber() << std::endl;
        std::cout << "Card Expiry: " << bPtr->acccountDebitCard()->expiryDate() << std::endl;
        std::cout << std::endl;
    }
}