#include "Functionalities.h"

void createObjects(Container &data) {
    data.push_back(
        std::make_shared<BankAccount>(
            "Krishna",
            AccountType::SAVING,
            9087456.09f,
            std::make_shared<DebitCard>(
                000,
                11234124512L,
                "12/29",
                DebitCardType::RUPAY)));

    data.push_back(
        std::make_shared<BankAccount>(
            "Aakanksha",
            AccountType::SAVING,
            8097566.09f,
            std::make_shared<DebitCard>(
                675,
                9876123456L,
                "11/30",
                DebitCardType::VISA)));
}