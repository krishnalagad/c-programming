#include <iostream>

int divide(int num1, int num2) {
    try {
        if(num2 == 0) 
            throw std::runtime_error("Cannot divide by zero!!\n");
        return (num1 / num2);
    } catch(const std::exception& ex) {
        std::cout<<"\nException caught: "<<ex.what();
        return 0;
    }
}

int main() {
    std::cout<<divide(12, 0);
    return 0;
}