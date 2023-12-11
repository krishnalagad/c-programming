#include <stdio.h>
struct Output{
    int out[100];
};

int main(void) {
    int arr[] = {35, 66, 23, 99, 112, 12, 224, 446, 123, 900};
    int eIndex = 0, oIndex = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    int arr1[size];
    int arr2[size];

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }  
    }

    for (int i = 0; i < size; i++){
        if (arr[i] % 2){
            arr2[oIndex++] = arr[i];
        } else {
            arr1[eIndex++] = arr[i];
        }  
    }    

    int size1 = eIndex;
    int size2 = oIndex;
    int mergedArr[size1 + size2];
    int i, j, k;
    i = j = k = 0;

    // compare 1st element of both arrays to get smallest one.
    if (arr1[i] < arr2[j]){
        mergedArr[k++] = arr1[i++];
        mergedArr[k++] = arr2[j++];
    } else {
        mergedArr[k++] = arr2[j++];
        mergedArr[k++] = arr1[i++];
    }  
    // add elements alternatively into merged array.
    while (i < size1 && j < size2){
        if (arr1[i] == 0 || arr2[j] == 0){
            continue;
        }
        mergedArr[k++] = arr1[i++];
        mergedArr[k++] = arr2[j++];
    }
    
    // if there are remaining elements in array1
    while (i < size1){
        mergedArr[k++] = arr1[i++];
    }

    // if there are remaining elements in array2
    while (j < size2){
        mergedArr[k++] = arr2[j++];
    }

    struct Output output;
    for (int i = 0; i < size1 + size2; i++){
        output.out[i] = mergedArr[i];
    }
    
    for (int i = 0; i < size1 + size2; i++){
        printf("%d ", output.out[i]);
    }
    printf("\n");
}