#include "Functionalities.hpp"
/*
    g++ function_wrapper.cpp Functionalities.cpp -g -o app && time ./app && rm app
*/
int main() {
    FnContainer fns;
    makeLambda(fns);

    DataContainer data {10, 20, 30};
    operation(fns, data);

    /*
        create a new partial function that attaches dummydata 
        to second param of operation()
    */
   std::vector<int> dummyData {2, 3, 4};
   auto bindedOperation = std::bind(operation, std::placeholders::_1, std::ref(dummyData));
   bindedOperation(fns);

    return 0;
}