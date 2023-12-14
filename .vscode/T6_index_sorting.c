#include <stdio.h>

void sortArrayTillIndex(int *arr, int len, int target) {
    if (len < target){
        printf("You can't perform operation beccause array size is less than target index.\n");
        return;
    } 
    printf("\n1st Loop\n");
    for (int i = 0; i <= target; i++){
        for (int j = 0; j <= target - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }  
        }   
    }
    printf("\n2nd Loop\n");
    for (int i = target + 1; i < len; i++){
        for (int j = target + 1; j < len - i + target; j++){
            if (arr[j] < arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }  
}

int main(void) {
    int arr[] = {1, 110, 340, 17, 8, 99, 23, 56, 11, 9, 101, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int targetIndex = 5;
    sortArrayTillIndex(arr, len, targetIndex);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 1;
}