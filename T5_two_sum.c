#include <stdio.h>

void solution(int *arr, int len, int target, int *res) {    
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - 1; j++){
            if (arr[i] + arr[j] == target){
                res[0] = j;
                res[1] = i;
                break;
            }  
        } 
    } 
}

int main(void) {
    int arr[] = {2, 3, 4, 6, 7, 12, 23, 45, 56, 67, 78, 100, 150};
    int res[2];
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 250;
    solution(arr, len, target, res);
    printf("\n[%d,%d]\n", res[0], res[1]);
    return 0;
}

