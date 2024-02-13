#include <iostream>
#include <thread>
#include <array>
#include <future>
#include "Functionalities.hpp"
/*
    Client code:
        g++ Main.cpp Functionalities.cpp DebitCard.cpp BankAccount.cpp -g -o app && time ./app && rm app
        g++ Main.cpp Functionalities.cpp DebitCard.cpp BankAccount.cpp -lpthread -g -o app 2>errors.txt && time ./app && rm app
*/
int main() {
    MapContainer data;
    AccountContainer accounts;

    std::future<void> r1 = std::async(std::launch::async, createObjects, std::ref(accounts), std::ref(data));
    // createObjects(accounts, data);
    r1.get();

    try {
        std::future<float> r2 = std::async(std::launch::async, findTotalBankBalance, std::ref(data));
        // float tot = findTotalBankBalance(data);
        float tot = r2.get();
        

        std::future<unsigned int> r3 = std::async(std::launch::async, countAbove50000BalanceAccount, std::ref(data));
        // int count = countAbove50000BalanceAccount(data);
        int count = r3.get();
        
        std::future<bool> r4 = std::async(std::launch::async, isAnyAccountWithNoCard, std::ref(data));
        bool flag = r4.get();
        
        std::future<std::optional<float>> r5 = std::async(std::launch::async, findBalanceById, std::ref(data), 9000001);
        std::optional<float> result = r5.get();

        std::cout << "\nTotal balance: " << tot << std::endl;
        std::cout << "Count of above 50000.0f amount: " << count << std::endl;
        if ( flag)
            std::cout << "At least one account exists with no debit card!!" << std::endl;
        else    
            std::cout << "No such account exist !!" << std::endl;

        if ( result.has_value())
            std::cout << "Account found with balance: " << result.value() <<std::endl;
        else    
            std::cerr << "No such account exist !!" << std::endl;

        std::cout << "\n";
    } catch(std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}