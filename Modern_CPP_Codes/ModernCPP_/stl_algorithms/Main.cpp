#include <iostream>
#include "Functionalities.h"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp DebitCard.cpp BankAccount.cpp -g -o app && time ./app && rm app
*/
int main() {
    Container data;
    createObjects(data);
    display(data);
    getNonNullDebitCardPointers(data);
    
    return 0;
}