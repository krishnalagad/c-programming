#include "Functionalities.h"
#include <algorithm>
#include <numeric>

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

float findTotalBankBalance(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    float totalBalance = std::accumulate(data.begin(), data.end(), 0.0f, [](float total, const BankPointer& ptr){
        return total + ptr->accountbalance();   // 1st param to lambda is always the initial answer 
    });                                         // 2nd param to lambda is object on which we have to perform action
    return totalBalance;
}

unsigned int countAbove50000BalanceAccount(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    size_t ans = std::count_if(data.begin(), data.end(), [](const BankPointer& ptr){ 
        return ptr->accountbalance() > 50000; 
    });
    return ans;
}

bool isAnyAccountWithNoCard(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    bool ans = std::any_of(data.begin(), data.end(), [](const BankPointer& ptr){ 
        return ptr->acccountDebitCard() == nullptr; 
    });
    return ans;
}

unsigned short findMaxBalanceCvvNumber(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    auto itr = std::max_element(data.begin(), data.end(), [](const BankPointer& ptr1, const BankPointer& ptr2){
        return ptr1->accountbalance() > ptr2->accountbalance();
    });
    return (*itr)->acccountDebitCard()->cvv();
}

std::string findMinBalanceExpiry(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    auto itr = std::min_element(data.begin(), data.end(), [](const BankPointer& ptr1, const BankPointer& ptr2){
        return ptr1->accountbalance() < ptr2->accountbalance();
    });
    return (*itr)->acccountDebitCard()->expiryDate();
}

CardContainer getDebitCardPointers(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");

    CardContainer result(data.size());
    Container temp(data.size());

    std::copy(data.begin(), data.end(), temp.begin());
    std::for_each(temp.begin(), temp.end(), [&result](const BankPointer& ptr){
        result.push_back(ptr->acccountDebitCard());
    });

    return result;
}

std::optional<CardContainer> getNonNullDebitCardPointers(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");
    
    CardContainer result(data.size());
    Container temp(data.size());

    std::copy_if(data.begin(), data.end(), temp.begin(), [](const BankPointer& ptr){
        ptr->acccountDebitCard() != nullptr;
    });

    std::for_each(temp.begin(), temp.end(), [&result](const BankPointer& ptr){
        result.emplace_back(ptr->acccountDebitCard());
    });

    return result;
}

std::optional<Container> findMatchingAccount(const Container &data) {
    if (data.empty()) 
        throw std::runtime_error("Empty container!!");

    Container result(data.size());
    // copy_if() returns iterator to the last copied element
    auto itr = std::copy_if(data.begin(), data.end(), result.begin(), [](const BankPointer& ptr){
        return (ptr->accountbalance() > 30000) && (ptr->acccountDebitCard() != nullptr);
    });

    std::size_t newSize = std::distance(result.begin(), itr);
    result.resize(newSize);
    
    return result;
}
