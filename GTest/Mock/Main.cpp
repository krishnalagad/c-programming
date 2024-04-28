#include <iostream>
#include "UnitTests.hpp"

/*
    g++ Main.cpp User.cpp UnitTests.hpp MyDatabase.cpp -o test_exec -lgtest -lgtest_main -pthread -lgmock -lgmock_main && 
    time ./test_exec && 
    rm test_exec
*/
int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
