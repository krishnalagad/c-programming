#include <stdio.h>
#include <stdlib.h>

void accept(int arr[], int len) {
    for (int i = 0; i < len; i++){
        printf("Enter data: ");
        scanf("%d", &arr[i]);
    }
}

void display(int *arr, int len) {
    for (int i = 0; i < len; i++){
        printf("%d -> ", arr[i]);
    }
    printf("NULL\n");
}

int main(void) {
    
    int n;
    printf("How many elements you want to store: ");
    scanf("%d", &n);

    int *ptr = (int*) malloc(n * sizeof(int));

    accept(ptr, n);
    display(ptr, n);

    free(ptr);
    return 1;
}