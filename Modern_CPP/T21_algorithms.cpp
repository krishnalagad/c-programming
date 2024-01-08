#include <iostream>
#include <algorithm>
#include <string>

int main() {
    // get min-max of two variables;
    int a = 10;
    int b = 20;
    std::cout<<"Max: "<<std::max(a, b)<<std::endl;

    std::string name1 = "Krishna";
    std::string name2 = "Lagad";
    std::cout<<"Min: "<<std::min(name1, name2)<<std::endl;

    // get max element from array;
    int arr[] = {1, 2, 3};  // max_element() returns address of max element;
    int *resAdd = std::max_element(arr, arr + 3);
    std::cout<<"maxAdd: "<<resAdd<<"\tbaseAdd: "<<arr<<std::endl;
    int index = (resAdd - arr);
    std::cout<<"Max Element: "<<*resAdd<<"\tIndex: "<<index<<std::endl;

}