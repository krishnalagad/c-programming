#include <stdio.h>

int main(void) {

    int arr[] = {2};
    int target = 9;
    int res = solution(arr, target);
    return 0;
}

int solution(int arr[], int target) {
    int len = sizeof(arr) / sizeof(arr[0]);
    if (len < 2){
        return 0;
    }
    printf("hiiii");
}