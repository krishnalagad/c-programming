/*
    scenario 5: I want to start a thread for a function that requires input, but can process some 
                commands even before input becomes available i.e. we can execute some part of the function without involving input parameter

                5(b) function returns some value    
                    - use future and promise model to send input to the function
                    Also use std::future<T> as return result value. where T is type of return
*/

#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Function to be executed by the thread
int threadFunction(std::promise<int>& inputPromise) {
    // Some part of the function executed before input becomes available
    std::cout << "Thread: Performing initial processing...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some processing time

    // Get the input value from the promise
    int input = inputPromise.get_future().get();

    // Process the input
    std::cout << "Thread Received input: " << input << std::endl;
    // Process the input further...

    // Return some value
    return input * 2;
}
/*
    g++ scenario5b.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    // Create a promise to pass input to the thread
    std::promise<int> inputPromise;

    // Launch the thread and pass the promise
    std::future<int> resultFuture = std::async(std::launch::async, threadFunction, std::ref(inputPromise));

    // Main thread continues to execute other tasks while waiting for input
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Fulfill the promise with input
    inputPromise.set_value(42);

    // Get the result from the future object
    int result = resultFuture.get();

    std::cout << "Result: " << result << std::endl;

    return 0;
}
