#include <iostream>
#include <cstring>

class LowBalanceException: public std::exception {
    std::string message;
    public:
        LowBalanceException() {
            this->message = "Low balance in account!!";
        }
        LowBalanceException(std::string message) {
            this->message = message;
        }
        std::string what() {
            return this->message;
        }
};

class Account {
    private: 
        int balance;
    public:
        Account(): balance(10000) {}
        void withdraw(int amount) {
            if(this->balance < 5000)
                throw LowBalanceException("Balance should not go lower than 5000.\n");
            if ((this->balance - amount) < 5000)
                throw LowBalanceException("Balance should not go lower than 5000.\n");
            this->balance -= amount;
            std::cout<<"\nRemaining Balance: "<<this->balance;
        }
};

class MyException: public std::exception {
    char message[100];
    public:
        MyException() {
            strcpy(this->message, "MyException occured!!");
        }
        MyException(const char *message) {
            strcpy(this->message, message);
        }
        char* what() {
            return this->message;
        }
};

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
        throw MyException();
        // throw CustomException();
    std::cout<<num<<std::endl;
}

int main() {
    Account a1;
    // std::cout<<divide(12, 0);
    try {
        // checkCustomException(1);
        a1.withdraw(2000);
        a1.withdraw(4000);
    } catch (const CustomException& ex) {
        std::cout<<"\nCustom Exception caught: "<<ex.what();
    } catch (MyException ex) {
        std::cout<<"\nMyException caught: "<<ex.what();
    } catch (LowBalanceException ex) {
        std::cout<<"\nLow balance exception caught: "<<ex.what();
    }
    return 0;
}