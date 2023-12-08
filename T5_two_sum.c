#include <stdio.h>

int solution(int *arr, int target) {    
    // int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sizeof(arr));
    // printf("%d\n", len);
    // if (len < 2){
    //     return 0;
    // }
    printf("hiiii");
}

int main(void) {

    int arr[] = {2, 3, 4, 6, 7};
    int target = 9;
    int res = solution(arr, target);
    return 0;
}

