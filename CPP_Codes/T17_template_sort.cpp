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
    int arr[size] = {12, 3, 5, 99, 2};
    sortArray(arr, size);
    for (int i = 0; i < size; i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}