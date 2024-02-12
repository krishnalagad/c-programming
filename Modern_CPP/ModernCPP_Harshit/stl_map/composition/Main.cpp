#include <iostream>
#include "Functionalities.hpp"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp DebitCard.cpp BankAccount.cpp -g -o app && time ./app && rm app
        g++ Main.cpp Functionalities.cpp DebitCard.cpp BankAccount.cpp -g -o app 2>errors.txt && time ./app && rm app
*/
int main() {
    MapContainer data;
    AccountContainer accounts;

    createObjects(accounts, data);

    try {
        float tot = findTotalBankBalance(data);
        std::cout << "\nTotal balance: " << tot << std::endl;
        int count = countAbove50000BalanceAccount(data);
        std::cout << "Count of above 50000.0f amount: " << count << std::endl;

        if (bool flag = isAnyAccountWithNoCard(data); flag)
            std::cout << "At least one account exists with no debit card!!" << std::endl;
        else    
            std::cout << "No such account exist !!" << std::endl;
        
        if (std::optional<float> result = findBalanceById(data, 9000001); result.has_value())
            std::cout << "Account found with balance: " << result.value() <<std::endl;
        else    
            std::cerr << "No such account exist !!" << std::endl;
    } catch(std::runtime_error& e) {
        std::cerr << e.what() << '\n';
    }
    
    
    return 0;
}