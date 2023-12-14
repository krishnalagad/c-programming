#include <stdio.h>

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
}

float solution(int *arr1, int len1, int *arr2, int len2) {
    int mergedArr[len1 + len2];
    int index = 0;
    for (int i = 0; i < len1; i++){
        mergedArr[index] = arr1[i];
        index += 1;
    }
    for (int i = 0; i < len2; i++){
        mergedArr[index] = arr2[i];
        index += 1;
    }
    sortArray(mergedArr, (len1 + len2));
    if ((len1 + len2) % 2){
        int outIndex = ((len1 + len2) / 2);
        return mergedArr[outIndex];
    } else{
        int outIndex = ((len1 + len2) / 2) + 1;
        float res = ((float) (mergedArr[outIndex - 1] + mergedArr[outIndex - 2])) / 2;
        return res;
    }
    
    return 1;
}
int main(void) {
    int arr1[] = {1, 3, 5, 8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 7};
    int len2 = sizeof(arr2)/ sizeof(arr2[0]);
    float result = solution(arr1, len1, arr2, len2);
    printf("Median of two arrays is: %f\n", result);
    return 0;
}