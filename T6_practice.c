#include <stdio.h>
#define SIZE 5


void reverse(int *arr, int len) {
    for (int i = len - 1; i >= 0; i--)
        printf("%d ", *(arr + i));
    printf("\n");
}

int main(void) {
    int arr[SIZE] = {5, 7, 12, 34, 89};
    int len = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, len);
    return 1;
}

