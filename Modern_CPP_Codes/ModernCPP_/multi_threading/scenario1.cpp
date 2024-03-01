/*
    scenario 1: I have a main program which includes a function that can be executed parallel to main 
    or concurrent to main without any dependency on main since there is no write to shared memory, 
    use std::thread with no synchronization primitive
*/

#include <iostream>
#include <thread>

// Function to be executed concurrently
void concurrentFunction() {
    // Perform some computation
    std::cout << "Concurrent function is executing..." << std::endl;
    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Concurrent function finished execution." << std::endl;
}
/*
    g++ scenario1.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    std::cout << "Main program started." << std::endl;

    // Start a thread to execute concurrentFunction
    std::thread concurrentThread(concurrentFunction);

    // Continue with main program execution
    std::cout << "Main program continues executing..." << std::endl;

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Main program finished executing." << std::endl;

    // Wait for the concurrent thread to finish
    concurrentThread.join();

    return 0;
}
