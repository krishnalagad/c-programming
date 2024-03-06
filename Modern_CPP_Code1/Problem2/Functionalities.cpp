#include "Functionalities.h"
#include "CustomMessageException.h"
#include <iostream>
#include <algorithm>

/*
    takes lvalue reference of container of LoanPointer where LoanPointer is shared ptr 
    of BankLoan class and returns void
*/
void createObjects(LoanPointerContainer& data){
    data.push_back(
        std::make_shared<BankLoan>(
            22, 59000, LoanIntent::PERSONAL, 35000, 16.02f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            25, 9600, LoanIntent::MEDICAL, 5500, 12.87f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            23, 65500, LoanIntent::MEDICAL, 35000, 15.23f, LoanStatus::NO));
    data.push_back(
        std::make_shared<BankLoan>(
            24, 54400, LoanIntent::MEDICAL, 35000, 14.27f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            21, 9900, LoanIntent::VENTURE, 2500, 7.14f, LoanStatus::NO));
    data.push_back(
        std::make_shared<BankLoan>(
            26, 77100, LoanIntent::EDUCATION, 35000, 12.42f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            24, 78956, LoanIntent::MEDICAL, 35000, 11.11f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            24, 83000, LoanIntent::PERSONAL, 35000, 8.9f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            21, 10000, LoanIntent::VENTURE, 1600, 14.74f, LoanStatus::YES));
    data.push_back(
        std::make_shared<BankLoan>(
            22, 85000, LoanIntent::VENTURE, 35000, 10.37f, LoanStatus::YES));         
}

/*
    takes constant lvalue reference of container of LoanPointer where LoanPointer is 
    shared ptr of BankLoan class and returns void.
*/
void averageLoanAmount(const LoanPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!");

    int amount = 0;
    int count = 0;
    for (const LoanPointer& ptr: data) {
        if (LoanIntent::MEDICAL == ptr->loanIntent()) {
            amount += ptr->loanAmount();
            count += 1;
        }
    }

    std::cout << "\nAverage loan amount of people whose loan intent is MEDICAL: " 
              << (amount / count) << std::endl;
}

/*
    takes constant lvalue reference of container of LoanPointer where LoanPointer is 
    shared ptr of BankLoan class and returns array of 4 integers.
*/
std::array<int, 4> valueCount(const LoanPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!");

    int countEducation = std::count_if(data.begin(), data.end(), [](const LoanPointer& ptr){ return ptr->loanIntent() == LoanIntent::EDUCATION;});
    int countPersonal  = std::count_if(data.begin(), data.end(), [](const LoanPointer& ptr){ return ptr->loanIntent() == LoanIntent::PERSONAL;});
    int countMedical   = std::count_if(data.begin(), data.end(), [](const LoanPointer& ptr){ return ptr->loanIntent() == LoanIntent::MEDICAL;});
    int countVenture   = std::count_if(data.begin(), data.end(), [](const LoanPointer& ptr){ return ptr->loanIntent() == LoanIntent::VENTURE;});

    std::array<int, 4> result = {countEducation, countPersonal, countMedical, countVenture};

    return result;
}

/*
    takes constant lvalue reference of container of LoanPointer where LoanPointer is 
    shared ptr of BankLoan class and returns void.
*/
void highestInterestRateForAcceptedLoans(const LoanPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!");
    
    auto it = std::max_element(data.begin(), data.end(), [](const LoanPointer& loan1, const LoanPointer& loan2){
        return loan1->intRate() < loan2->intRate();
    });

    std::cout << "\nLoan Account with Highest Interest rate for all the accepted loans is: \n" << **it  << std::endl;
}

/*
    takes constant lvalue reference of container of LoanPointer where LoanPointer is 
    shared ptr of BankLoan class and returns LoanPointerContainer.
*/
LoanPointerContainer getContainerMatchesConditions(const LoanPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!\n");
    
    LoanPointerContainer result;
    for (const LoanPointer& ptr: data) {
        if (ptr->loanAmount() > 20000 && ptr->loanAmount() < 40000) {
            if (ptr->status() == LoanStatus::YES && ptr->personAge() > 23) 
                result.push_back(ptr);
            else 
                throw CustomMessageException("User age is not over 23 or Loan status is NO\n");
        } else 
            throw CustomMessageException("Loan amount is not between 20000 & 40000\n");
    }

    return result;
}

/*
    takes constant lvalue reference of container of LoanPointer, Loan intent value where LoanPointer is 
    shared ptr of BankLoan class and returns LoanPointerContainer.
*/
float getContainerMatchesIntent(const LoanPointerContainer& data, LoanIntent intent) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!\n");
    // auto it = std::max_element(data.begin(), data.end(), [intent](const LoanPointer& loan1, const LoanPointer& loan2){
    //     return loan1->loanIntent() == intent &  loan2->loanIntent() == intent;
    // });
    // std::cout << "\nAns: " << **it;

    LoanPointerContainer result;
    for (const LoanPointer& ptr: data) {
        if (ptr->loanIntent() == intent) 
            result.push_back(ptr);
    }

    auto it = std::max_element(result.begin(), result.end(), [](const LoanPointer& loan1, const LoanPointer& loan2){
        return loan1->intRate() < loan2->intRate();
    });
    // std::cout << "\nAns: " << **it;
    return it->get()->intRate();
}

/*
    takes constant lvalue reference of container of LoanPointer where LoanPointer is 
    shared ptr of BankLoan class and returns void.
*/
void getMinMaxAge(const LoanPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("LoanPointerContainer is empty !!\n");

    auto itMax = std::max_element(data.begin(), data.end(), [](const LoanPointer& loan1, const LoanPointer& loan2){
        return loan1->personAge() < loan2->personAge();
    });

    auto itMin = std::max_element(data.begin(), data.end(), [](const LoanPointer& loan1, const LoanPointer& loan2){
        return loan1->personAge() > loan2->personAge();
    });

    std::cout << "Max Age: " << itMax->get()->personAge() << "\nMin Age: " << itMin->get()->personAge() << std::endl;
}
