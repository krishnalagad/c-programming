/*
    scenario 4: Function to be executed in thread returns a value 
    use std::future<T> as return value and launch thread with std::async
*/

#include <iostream>
#include <future>

// Function to be executed by the thread
int threadFunction(int x, int y) {
    // Perform some computation
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    return x + y;
}
/*
    g++ scenario4.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    // Launch thread asynchronously and get the future object
    std::future<int> resultFuture = std::async(std::launch::async, threadFunction, 10, 20);

    // Main thread continues its work while the other thread is executing
    std::cout << "Main thread is working its own tasks!!" << std::endl;

    // Get the result from the future object
    int result = resultFuture.get();

    std::cout << "Result: " << result << std::endl;

    return 0;
}
