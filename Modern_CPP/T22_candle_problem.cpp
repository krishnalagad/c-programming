#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {4, 4, 1, 3};
    std::sort(std::begin(arr), std::end(arr));
    int result = std::count(std::begin(arr), std::end(arr), *(std::end(arr) - 1));
    std::cout<<"\n"<<result<<std::endl;
    return 0;
}