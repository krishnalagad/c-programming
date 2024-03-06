#include <stdio.h>
#include "header.h"

// sort aray ascending 
void sortAscending(int *arr, int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } 
    }
}

// sort array descending
void sortDescending(int *arr, int len){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } 
    }
}

void ArraySorting(int *arr, int len) {
    int tempEven[len], evenIndex = 0;
    int tempOdd[len], oddIndex = 0;
    for (int i = 0; i < len; i++){      // seperating even and odd elements in to two arrays
        if (arr[i] % 2){
            tempOdd[oddIndex] = arr[i];
            oddIndex += 1;
        } else {
            tempEven[evenIndex] = arr[i];
            evenIndex += 1;
        }  
    }
    int evenArr[evenIndex];
    int oddArr[oddIndex];
    for (int i = 0; i < evenIndex; i++)
        evenArr[i] = tempEven[i];
    for (int i = 0; i < oddIndex; i++)
        oddArr[i] = tempOdd[i];

    // perform sort opetration on both the arrays accoring to sriteria
    sortAscending(evenArr, evenIndex);
    sortDescending(oddArr, oddIndex);

    // merge both arrays into one final array
    int result[evenIndex + oddIndex];
    int index;
    for (index = 0; index < evenIndex; index++){
        result[index] = evenArr[index];
    }
    for (int i = 0; i < oddIndex; i++){
        result[index] = oddArr[i];
        index += 1;
    }
    printf("\nResult array: ");
    for (int i = 0; i < len; i++){
        printf("%d ", result[i]);
    }
    printf("\n\n");
}