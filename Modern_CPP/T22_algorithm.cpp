#include <iostream>
#include <algorithm>

// custom find method implementation
template <typename T>
T* find(T *startPtr, T* lastPtr, T key) {
    while(startPtr != lastPtr) {
        if (key == *startPtr)
            return startPtr;
        ++startPtr;
    }
    return startPtr;
}

int main() {
    // find element from array
    int arr[] = {1,2,3,4,5,6,7,8,9,9,0};
    int *ptr = std::find(std::begin(arr), std::end(arr), 1);
    if(ptr == std::end(arr))
        std::cout<<"Element not found!!"<<std::endl;
    else {
        std::cout<<"Base address: "<<arr<<std::endl;
        std::cout<<"Address where element is present: "<<ptr<<"\nIndex: "<<ptr - arr<<std::endl;
    }

    // binary search function
    bool isFound = std::binary_search(std::begin(arr), std::end(arr), 0);
    if (isFound)
        std::cout<<"Binary search: Element is found!!\n";
    else 
        std::cout<<"Binary search: Element is not present!!\n";

    // upper bound of an array
    int* ptr1 = std::upper_bound(std::begin(arr), std::end(arr), 9);    // internally uses binary search
    int* ptr2 = std::lower_bound(std::begin(arr), std::end(arr), 0);
    std::cout<<"Base address: "<<arr<<std::endl;
    std::cout<<"Upper bound where element is present: "<<ptr1<<std::endl;
    std::cout<<"Lower bound where element is present: "<<*ptr2<<std::endl;

    return 0;
}