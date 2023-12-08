#include <stdio.h>

void sortArrayTillIndex(int *arr, int len, int target) {
    if (len < target){
        printf("You can't perform operation beccause array size is less than target index.\n");
        return 0;
    }  
}

int main(void) {
    int arr[] = {17, 8, 99, 23, 56, 11, 9, 101, 2};
    int targetIndex = 5;
    int len = sizeof(arr) / sizeof(arr[0]);
    sortArrayTillIndex(arr, len, targetIndex);
    return 1;
}