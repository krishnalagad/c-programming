#include "Functionalities.hpp"

/*
    Client code goes here
    - g++ Main.cpp Functionalities.cpp -o app && ./app && rm app
*/
int main() {

    FnContainer fns;
    createLambda(fns);

    DataContainer data {"abcd", "Krshn", "xyz", "mno"};
    performOperation(fns, data);

    return 0;
}