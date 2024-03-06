#ifndef THREADHANDLER_HPP
#define THREADHANDLER_HPP

#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <vector>
#include "CustomMessageException.hpp"

class ThreadHandler {
    private:
        std::mutex mt;
        std::condition_variable cv;
        bool flag;
        int n;
        std::vector<int> numbers;
        
    public:
        ThreadHandler() = default;
        ThreadHandler(const ThreadHandler&) = default;
        ThreadHandler(ThreadHandler&&) = default;
        ThreadHandler& operator=(const ThreadHandler&) = default;
        ThreadHandler& operator=(ThreadHandler&) = default;
        ~ThreadHandler() = default;

        // custom parameterized constructor
        ThreadHandler(int n);

        // member functions
        void operation();   // consumer function
        void inputCapture();    // publisher function

        void printData();
};

#endif // THREADHANDLER_HPP
