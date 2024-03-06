#include "ThreadHandler.hpp"

ThreadHandler::ThreadHandler(int n): n(n) {}

void ThreadHandler::inputCapture() {
    if (n <= 0)
        std::cout << "Size of container should not be less than zero!!" << std::endl;

    numbers.resize(n);      // resize the vector to size enter by user

    /*
        Accept value from user and store them in vector
    */
    for (int i = 0; i < n; i++) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    std::lock_guard<std::mutex> lock(mt);
    flag = true;

    cv.notify_one();    // Now notify to consumer thread that values are ready
}

void ThreadHandler::operation() {
    if (numbers.empty())
        std::cout << "Data container is empty!!" << std::endl;
    
    std::unique_lock<std::mutex> lock(mt);
    cv.wait(lock, [this](){ return flag; });

    for (int i = 0; i < n; i++) {
        numbers[i] = numbers.at(i) * numbers.at(i);
    }
}

void ThreadHandler::printData() {
    std::cout << "\nSquared Data: ";
    for (int val: numbers) {
        std::cout << val << "  ";
    }
    std::cout << "\n";
}