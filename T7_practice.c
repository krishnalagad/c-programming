#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int a = 10, b = 20, c = 30;
    int *intPtr[3] = {&a, &b, &c};
    for (int i = 0; i < 3; i++){
        printf("%d ", *intPtr[i]);
    }
    printf("\n");

    // --------------------------------------------------------------------------------

    // pointer to pointer (2D array)
    int row = 3, col = 4;
    int **ptr = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++){
        ptr[i] = (int*) malloc(c * sizeof(int));
    }
    

    return 1;
}