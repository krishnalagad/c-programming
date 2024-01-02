#include <iostream>



class CustomException: public std::runtime_error {
    public: 
        CustomException(): std::runtime_error("Custom exception occured!!\n") {}
        CustomException(const char* message): std::runtime_error(message) {}
};

int divide(int num1, int num2) {
    try {
        if(num2 == 0) 
            throw std::runtime_error("Cannot divide by zero!!\n");
        return (num1 / num2);
    } catch(const std::runtime_error& ex) {
        std::cout<<"\nException caught: "<<ex.what();
        return -1;
    }
}

void checkCustomException(int num) {
    if(num == 0)
        throw CustomException("Number cannot be zero!!\n");
    else if (num == 1)
        throw CustomException();
    std::cout<<num<<std::endl;
}

int main() {
    std::cout<<divide(12, 0);
    try {
        checkCustomException(12);
    } catch (const CustomException& ex) {
        std::cout<<"\nCustom Exception caught: "<<ex.what();
    }
    return 0;
}