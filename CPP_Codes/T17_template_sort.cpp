#include <iostream>

template<class T>
void sortArray(T *arr, int size) {
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size = 5;
    int arr1[size] = {12, 3, 5, 99, 2};
    sortArray(arr1, size);
    for (int i = 0; i < size; i++)
        std::cout<<arr1[i]<<" ";
    std::cout<<std::endl;

    float arr2[size] = {12.2f, 3.7f, 5.6f, 99.9f, 2.3f};
    sortArray(arr2, size);
    for (int i = 0; i < size; i++)
        std::cout<<arr2[i]<<" ";
    std::cout<<std::endl;

    char arr3[size] = {'k', 'r', 'i', 's', 'h'};
    sortArray(arr3, size);
    for (int i = 0; i < size; i++)
        std::cout<<arr3[i]<<" ";
    std::cout<<std::endl;
    return 0;
}