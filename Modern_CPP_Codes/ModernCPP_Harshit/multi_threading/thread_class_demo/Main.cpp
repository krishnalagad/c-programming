#include "ThreadOperation.hpp"

/*
    g++ ThreadOperation.cpp Main.cpp Functionalities.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    ThreadOperation obj1(10);
    std::thread t1(&ThreadOperation::square, &obj1);
    std::thread t2(&ThreadOperation::cube, &obj1);
    std::thread t3(&ThreadOperation::produceValueForCube, &obj1);

    if (t1.joinable())
        t1.join();

    if (t2.joinable())
        t2.join();

    if (t3.joinable())
        t3.join();
    

    return 0;
}