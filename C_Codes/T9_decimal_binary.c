#include <stdio.h>

int main(void) {
    int decimal_number, binary_number = 0, i = 1, remainder;

    printf("Enter any decimal number: ");
    scanf("%d", &decimal_number);

    while (decimal_number != 0) {
        remainder = decimal_number % 2;
        binary_number += remainder * i;
        decimal_number /= 2;
        i *= 10;
    }
    
    printf("Binary number: %d\n", binary_number);
    return 0;
}