#include <iostream>
#include <algorithm>
#include <string>

template <class T>
T* getMax(T *first, T *last) {
    T *max = first;
    while (first < last){
        if(*first > *max) 
            max = first;
        ++first;
    }
    
    return max;

    // T *result = std::max_element(first, last);
    // return *result;
}

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
    // int *ptrMax = std::max_element(arr, arr + 3);
    int *ptrMax = std::max_element(std::begin(arr), std::end(arr));
    std::cout<<"maxAdd: "<<ptrMax<<"\tbaseAdd: "<<arr<<std::endl;
    int index = (ptrMax - arr);
    std::cout<<"Max Element: "<<*ptrMax<<"\tIndex: "<<index<<std::endl;

    // get max element using template
    int *ptrRes = getMax(arr, arr + 3);
    index = ptrRes - arr;
    std::cout<<"Max Element: "<<*ptrRes<<"\tIndex: "<<index<<std::endl;

    // get max element for string arr;
    std::string strArr[] = {"Krishna", "Dilip", "Lagad"};
    std::string *ans = getMax(strArr, strArr + 3);
    std::cout<<"Max Element: "<<*ans<<std::endl;

    // swap with max element
    std::cout<<"strArr[0] = "<<strArr[0]<<"  strArr[1] = "<<strArr[2]<<std::endl;
    std::swap(strArr[0], *ans);
    std::cout<<"strArr[0] = "<<strArr[0]<<"  strArr[1] = "<<strArr[2]<<std::endl;

    return 0;
}