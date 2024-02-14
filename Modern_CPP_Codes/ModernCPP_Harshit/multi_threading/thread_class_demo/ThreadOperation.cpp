#include "ThreadOperation.hpp"
#include <iostream>

void ThreadOperation::square() {
    std::lock_guard<std::mutex> lk(mt);
    std::cout << "Square: " << _value * _value << std::endl;
}

// void ThreadOperation::cube() {
//     std::lock_guard<std::mutex> lk(mt);
//     std::cout << "Cube: " << _value * _value * _value << std::endl;
// }

void ThreadOperation::produceValueForCube() {
    std::cout << "Enter number: ";
    int num;
    std::cin >> num;
    std::lock_guard<std::mutex> lk(mt);
    _cubeVal = num;
    _cubeValAvailable = true;
    cv.notify_one();
}

void ThreadOperation::cube() {
    // std::lock_guard<std::mutex> lk(mt);
    // std::cout << "Cube: " << _value * _value * _value << std::endl;

    std::unique_lock<std::mutex> lk(mt);
    cv.wait(lk, [&](){ return _cubeValAvailable; });
    std::cout << "Cube: " << _cubeVal * _cubeVal * _cubeVal << "\n";
    lk.unlock();
}

std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs) {
    os << " _value: " << rhs._value;
    return os;
}
