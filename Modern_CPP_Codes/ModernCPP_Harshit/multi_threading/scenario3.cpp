/*
    scenario 3: creating and managing multiple threads use a container like array or list to create 
                a container of threads synchronization may or may not be required
*/

#include <iostream>
#include <vector>
#include <thread>

// Function to be executed by each thread
void threadFunction(int threadId) {
    std::cout << "Thread " << threadId << " is executing." << std::endl;
    // Simulate some computation
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\nThread " << threadId << " finished execution." << std::endl;
}
/*
    g++ scenario3.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    std::cout << "Main program started." << std::endl;

    // Number of threads to create
    const int numThreads = 5;

    // Container to hold threads
    std::vector<std::thread> threads;

    // Create and launch threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(threadFunction, i); // Create thread and add it to the container
    }

    // Join threads with the main thread
    for (std::thread& t : threads) {
        t.join();
    }

    std::cout << "Main program finished executing." << std::endl;

    return 0;
}
