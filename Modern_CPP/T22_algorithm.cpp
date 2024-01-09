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

bool isOdd(int a) {
    return a % 2 != 0;
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

    // get index of element using binary search
    int arr1[] = {1,2,3,4,5,6,7};
    int key = 7;
    bool res = std::binary_search(std::begin(arr1), std::end(arr1), key);
    int *indexPtr = std::lower_bound(std::begin(arr1), std::end(arr1), key);
    if (res)
        std::cout<<"\nBinary search: Element is found!!\nIndex of element: "<<(*indexPtr - 1) <<std::endl;
    else 
        std::cout<<"\nBinary search: Element is not present!!\n";

    // get the count of same element in array
    int cnt = std::count(std::begin(arr), std::end(arr), 0);
    std::cout<<"Count: "<<cnt<<std::endl;

    // sort array element
    int arr2[] = {4, 4, 1, 3, 5, 9};
    std::sort(std::begin(arr2), std::end(arr2));
    int result = std::count(std::begin(arr2), std::end(arr2), *(std::end(arr2) - 1));
    std::cout<<"\nCandles: "<<result<<std::endl;

    // sorting in descending
    std::sort(std::begin(arr2), std::end(arr2), std::greater<int>());
    for(int i = 0; i < 6; i++)
        std::cout<<arr2[i]<<" ";

    // count_if
    result = std::count_if(std::begin(arr2), std::end(arr2), isOdd);
    std::cout<<"\nCount_if: "<<result<<std::endl;

    return 0;
}