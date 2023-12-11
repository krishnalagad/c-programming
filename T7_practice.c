#include <stdio.h>
#include <stdlib.h>

void display(int (*)[]);

void display(int (*arr)[3]) {
    // printf("\nAddresses: \n");
    // printf("%d\n", (void *)arr);
    // arr++;
    // printf("%d\n", (void *)arr);
    // arr++;
    // printf("%d\n", (void *)arr);
    // printf("\nElements:\n");

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
}

int main(void) {

    printf("Array of pointerss: \n");
    int a = 10, b = 20, c = 30;
    int *intPtr[3] = {&a, &b, &c};
    for (int i = 0; i < 3; i++){
        printf("%d ", *intPtr[i]);
    }
    printf("\n\n");

    // --------------------------------------------------------------------------------

    // pointer to pointer (2D array)
    printf("Pointer to pointers: \n");
    int row = 3, col = 4;
    int **ptr = (int**) malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++){
        ptr[i] = (int*) malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("Enter data for [%d][%d]: ", i, j);
            scanf("%d", &ptr[i][j]);
        } 
    }

    // Display the values stored in the array
    printf("\nValues stored in the array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < row; i++){
        printf("Memory has been freed for block: %p\n", ptr[i]);
        free(ptr[i]);
    }
    printf("Memory has been freed for block: %p\n", ptr);
    free(ptr);
    
    // ------------------------------------------------------------------------------------

    // passing 2D array as parameter
    printf("passing 2D array as parameter: \n");
    int arr[2][3] = {2,3,4,5,6,6};
    display(arr);

    return 0;
}