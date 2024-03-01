/*
    scenario 6: One section of my program performs an action which generates data values. 
            These values maybe stored in some container/memory location.
            I want to execute some function to consume/operate on generated values but I 
            have certain expectations/limitations

            A) CONSUMPTION SHOULD BE TRIGGERED ONLY WHEN A VALUE BECOMES AVAILABLE
            B) DATA TO BE CONSUMED/PROCESSED SHALL NOT BE PROVIDED AS INPUT, SINCE
                i) Values are generated periodically
                ii) values are generated but maintained outside of the consumer
            Here use condition variable concept
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::queue<int> dataQueue; // Queue to store generated data
std::mutex mtx; // Mutex to protect shared data
std::condition_variable cv; // Condition variable for signaling data availability

// Producer function to generate data periodically
void producerFunction() {
    for (int i = 1; i <= 5; ++i) {
        {
            std::lock_guard<std::mutex> lock(mtx); // Lock the mutex
            dataQueue.push(i); // Generate data and push it into the queue
            std::cout << "Produced: " << i << std::endl;
        }
        cv.notify_one(); // Notify the consumer that data is available
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate periodic data generation
    }
}

// Consumer function to consume data when available
void consumerFunction() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex
        // Wait until data is available or until explicitly notified
        cv.wait(lock, [] { return !dataQueue.empty(); });
        // Process the data
        int data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumed: " << data << std::endl;
        lock.unlock(); // Unlock the mutex
        // Process the data further if needed
        // Simulate processing time
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
/*
    g++ scenario6.cpp -lpthread -g -o app && time ./app && rm app
*/
int main() {
    // Create producer and consumer threads
    std::thread producer(producerFunction);
    std::thread consumer(consumerFunction);

    // Join the threads with the main thread
    producer.join();
    consumer.join();

    return 0;
}
