#include <stdio.h>
#include "header.h"

int main() {
    int iterations;
    printf("\nEnter iteration value: ");
    scanf("%d", &iterations);
    if (iterations <= 0){   // validation check for negative and zero input.
        printf("Zeros and negtive integers are not acceptable, please enter positive integers.\n");
        main(); // call to main function so that it doesnt required to execute program again.
    }
    if (iterations > 30) {  // validation check if ieration value exceeds 30.
        printf("Iteration value should not exceed 30. Please enter value within 1 to 30\n");
        main();
    }
    
    genNumSeq(iterations);  // call to a function with actual parameter.
    return 0;
}