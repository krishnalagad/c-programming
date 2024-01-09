#include <iostream>
#include <algorithm>

bool isOdd(int num) {
    return num % 2 != 0;
}

int mycount_if(int *start, int *last, bool (*pf)(int)) {
    int c = 0;
    while(start != last) {
        if(pf(*start)) 
            c++;
        ++start;
    }
    return c;
}

int main() {
    bool (*ptr)(int) = isOdd;
    std::cout<<ptr(12)<<std::endl;
    std::cout<<ptr(13)<<std::endl;

    int arr[] = {4, 4, 1, 3, 5, 9};
    // int result = mycount_if(std::begin(arr), std::end(arr), isOdd);
    int result = mycount_if(std::begin(arr), std::end(arr), [](int num){return num % 2 != 0;});
    std::cout<<result<<std::endl;
    return 0;
}