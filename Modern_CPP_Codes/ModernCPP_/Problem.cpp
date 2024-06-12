#include <iostream>
#include <array>

int solution(int *arr, int sum, int size) {
    int result = 0;
    int temp = sum;
    int tempSum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] == temp) {
                result += 1;
                // break;
            }
            tempSum += arr[j];
            if (tempSum == sum) {
                result += 1;
            }
        }
        
    }

    return result;
}

/*
    g++ Problem.cpp -o app && time ./app && rm app
*/
int main() {
    int arr[] = {1,2,3,4};
    int len = sizeof(arr) / sizeof(arr[0]);
    int sum = 3;
    int result = solution(arr, sum, len);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
