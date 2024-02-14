#ifndef THREADOPERATION_HPP
#define THREADOPERATION_HPP

#include <mutex>
#include <thread>
#include <ostream>
#include <condition_variable>

class ThreadOperation {
    private:
        std::mutex mt;
        int _cubeVal {-1};
        bool _cubeValAvailable {false};
        int _value;
        std::condition_variable cv;

    public:
        ThreadOperation() = delete;
        ThreadOperation(const ThreadOperation&) = delete;
        ThreadOperation(ThreadOperation&&) = delete;
        ThreadOperation& operator=(const ThreadOperation&) = delete;
        ThreadOperation& operator=(ThreadOperation&&) = delete;
        ~ThreadOperation() = default;

        explicit ThreadOperation(int value): _value(value) {}

        void square();
        void cube();    // consumer function

        void produceValueForCube();     // producer function

        friend std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs);
};

#endif // THREADOPERATION_HPP
