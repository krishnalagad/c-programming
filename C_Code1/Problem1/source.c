#include <stdio.h>
#include "header.h"

void genNumSeq(int iterations) {
    int value = 3; 
    const int val = 2;  // constant value because no changes happening in it.
    int temp  = 1;
    printf("%d ", value);
    for (int i = 1; i < iterations; i++){
        printf("%d ", (value * val - 1));
        temp *= 2;  // multiplying temp by 2 for each iteration so that it beccomes 3, 5, 9, 17... everytime.
        value += temp;
    }   
    printf("\n");
}