#include "Functionalities.hpp"

void printSumOfNNumbers(int n) {
    int tot = (n * (n + 1)) / 2;
    std::cout << "Sum of first " << n << " positive numbers is: " << tot << std::endl;
}

void displayEvenNumbersInVector(const std::vector<int>& data) {
    if (data.empty()) 
        std::cout << "Data Container is empty!!" << std::endl;
    
    std::cout << "\nEven numbers are: ";
    for (const int& num: data)
        if (num % 2 == 0)
            std::cout << num << " ";
    std::cout << "\n";
}

void generateAndDisplayIntegers(std::promise<int>& promise) {
    int n = promise.get_future().get();
    if (n < 0)
        std::cout << "Value should not be below 0 !!";

    std::array<int, 5> arr;
    for (int i = 0; i < 5; i++)
        arr[i] = n++;
    std::cout << "\nArray Elements: ";
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << "  ";
    std::cout << "\n";
}

void generateAndStoreSquares(std::array<int, 5>& arr) {
    if (arr.empty())
        std::cout << "Array is empty!!\n";
    
    std::vector<int> result;
    for(int num: arr) 
        result.push_back(num * num);

    std::cout << "\nSquare of numbers in array: ";
    for (int res: result) 
        std::cout << res << "  ";
    std::cout << "\n";
}

void generateAndStoreCube(std::array<int, 5>& arr) {
    if (arr.empty())
        std::cout << "Array is empty!!\n";
    
    std::vector<int> result;
    for(int num: arr) 
        result.push_back(num * num * num);

    std::cout << "\nCube of numbers in array: ";
    for (int res: result) 
        std::cout << res << "  ";
    std::cout << "\n";
}

void createThreads(Container& threads, int f1_param, std::vector<int>& f2_param, std::array<int, 5>& f3_param, 
                    std::array<int, 5>& f4_param){

    threads[0] = std::thread(printSumOfNNumbers, std::ref(f1_param));
    threads[1] = std::thread(displayEvenNumbersInVector, std::ref(f2_param));
    threads[2] = std::thread(generateAndStoreSquares, std::ref(f3_param));
    threads[3] = std::thread(generateAndStoreCube, std::ref(f4_param));

}
