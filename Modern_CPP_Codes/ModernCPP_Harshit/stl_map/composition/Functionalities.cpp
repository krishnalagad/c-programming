#include "Functionalities.hpp"
#include "AccountType.h"
#include <iostream>
#include <numeric>

void createObjects(AccountContainer& accounts, MapContainer& data) {
    accounts.emplace_back(std::make_shared<BankAccount>(
        "Krishna", AccountType::SAVING, 50001.0f, std::make_shared<DebitCard>(
            109, 1283458736L, "09/34", DebitCardType::RUPAY)));

    accounts.emplace_back(std::make_shared<BankAccount>(
            "Rohan", AccountType::SAVING, 40500.0f, std::make_shared<DebitCard>(
                111, 389768279L, "09/25", DebitCardType::MASTERCARD)));

    accounts.emplace_back(std::make_shared<BankAccount>(
            "Kaveri", AccountType::CURRENT, 34000.0f, std::make_shared<DebitCard>(
                897, 930284789L, "03/25", DebitCardType::RUPAY)));
    
    accounts.emplace_back(std::make_shared<BankAccount>(
            "Aakanksha", AccountType::PENSION, 54000.0f));

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
    data.emplace(
        std::make_pair<unsigned long, AccountPointer>(
            accounts[3]->accountNumber(), std::move(accounts[3])
        )
    );
    
}

float findTotalBankBalance(const MapContainer &data) {
    if (data.empty()) 
        throw std::runtime_error("Empt Container!");

    float answer = std::accumulate(data.begin(), data.end(), 
                    0.0f, [](float total, std::pair<unsigned long, AccountPointer>&& p){
                        return total + p.second->accountbalance();
                    });
    return answer;
}

unsigned int countAbove50000BalanceAccount(const MapContainer &data) {
    if (data.empty()) 
        throw std::runtime_error("Empt Container!");
    
    std::size_t count = std::count_if(data.begin(), data.end(),
                    [](std::pair<unsigned long, AccountPointer>&& p){
                        return p.second->accountbalance() > 50000;
                    } );
    return count;
}

bool isAnyAccountWithNoCard(const MapContainer &data) {
    if (data.empty()) 
        throw std::runtime_error("Empt Container!");
    
    bool res = std::any_of(data.begin(), data.end(), 
                [](std::pair<unsigned long, AccountPointer>&& p){
                    return p.second->acccountDebitCard() == nullptr;
                });
    return res;
}

std::optional<float> findBalanceById(const MapContainer &data, unsigned long accNumber) {
    if (data.empty()) 
        throw std::runtime_error("Empt Container!");

    auto itr = std::find_if(data.begin(), data.end(), 
                [&](std::pair<unsigned long, AccountPointer>&& p){
                    return p.second->accountNumber() == accNumber;
                });

    if (itr == data.end())
        return std::nullopt;
    return (*itr).second->accountbalance();
}