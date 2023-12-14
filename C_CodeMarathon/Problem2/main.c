#include <stdio.h>
#include "header.h"

int main() {
    int size, data;
    printf("\nEnter size of an array: ");
    scanf("%d", &size);
    if (size > 50){     // check for max size
        printf("Array size should not exceed 50.");
        main(); // call to main so program won't collapse.
    }
    
    int arr[size];
    for (int i = 0; i < size; i++){
        printf("\nEnter data %d: ", (i+1));
        scanf("%d", &data);
        if (data <= 0){
            printf("Please enter Non-zero positive integers only.");
            i -= 1;
            continue;
        } 
        arr[i] = data;
    }
    ArraySorting(arr, size);
    return 0;
}