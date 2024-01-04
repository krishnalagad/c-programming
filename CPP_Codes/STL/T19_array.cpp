#include <iostream>
#include <array>

int main() {
    std::array<int, 4> arr = {1, 2, 3, 4};
    std::cout<<"\nSize of an STL array: "<<arr.size();
    std::cout<<"\nFirst element of array: "<<arr.front();
    std::cout<<"\nLast element of array: "<<arr.back();
    std::cout<<"\nElement at index 2 is "<<arr.at(2);
    std::cout<<"\nEmpty or not: "<<(arr.empty() ? "True" : "False");
    std::cout<<"\n";
    return 0;
}