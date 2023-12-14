#include <stdio.h>
#define SIZE 9

void reverse(int *arr, int len) {
    printf("Reverse array: ");
    for (int i = len - 1; i >= 0; i--)
        printf("%d ", *(arr + i));
    printf("\n");
}

void countOccurance(int *arr, int len, int element) {
    int count = 0;
    for (int i = 0; i < len; i++)
        if (*(arr + i) == element)
            count++;
    if (count)
        printf("\nCount of occurance: %d\n\n", count);
    else
        printf("\nElement is not found in an array\n");
    
}

void sortArray(int *arr, int len) {
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }   
    } 
    printf("Sorted array: ");
    for (int i = 0; i < len; i++){
        printf("%d ", *(arr + i));
    }
}

void findMaxWithoutSort(int *arr, int len) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i] > max)
            max = arr[i]; 
        else if (arr[i] < min)
            min = arr[i];
    }
         
    printf("\nMaximun element: %d, Minimum element: %d\n", max, min);    
}

int main(void) {
    int arr[SIZE] = {5, 7, 12, 34, 89, 7, 12, 7, 34};
    int len = sizeof(arr) / sizeof(arr[0]);
    int element;
    reverse(arr, len);

    // printf("Enter number: ");
    // scanf("%d", &element);
    // countOccurance(arr, len, element);

    sortArray(arr, len);
    findMaxWithoutSort(arr, len);

    return 1;
}

