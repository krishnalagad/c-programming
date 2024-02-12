#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
bool compare(T a, T b) {
    std::cout<<"Comparing: "<<a<<"  "<<b<<std::endl;
    return a < b;
}

int main() {
    int arr[] = {4, 4, 1, 3};
    std::sort(std::begin(arr), std::end(arr));
    int result = std::count(std::begin(arr), std::end(arr), *(std::end(arr) - 1));
    std::cout<<"\n"<<result<<std::endl;

    // sorting in descending
    std::sort(std::begin(arr), std::end(arr), std::greater<int>());
    for(int i = 0; i < 4; i++)
        std::cout<<arr[i]<<" ";

    return 0;
}