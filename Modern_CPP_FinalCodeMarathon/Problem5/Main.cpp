#include <iostream>
#include "Functionalities.hpp"

/*
    g++ Main.cpp Functionalities.cpp Unit.cpp Account.cpp -o app && time ./app && rm app
*/
int main() {
    AccountPointerMap data;
    createObjects(data);
    try {
        bool flag = addfareAmount(data, 1004, "UNIT01", 45050);
        std::string str = flag ? "True" : "False";
        std::cout << "\nAdd fare amount: " << str << std::endl;

        std::cout << "Total revenue for account: " << getTotalRevenueForAccount(data, 1006) << std::endl;

        std::cout << "Bonus amount for the given account is: " << getBonusAmountForAccount(data, 1004) << std::endl;
    } catch(CustomMessageException& e) {
        std::cerr << e.what() << '\n';
    } catch(RecordNotFoundException& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}