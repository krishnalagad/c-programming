#include <stdio.h>

int main(void){

    int num1 = 10, num2 = 20;
    int num3 = num1++ || num2++;
    printf("\nAfter post incr: num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);
    num1 = 10, num2 = 20;
    num3 = ++num1 || ++num2;
    printf("\nAfter pre incr: num1 = %d, num2 = %d, num3 = %d\n", num1, num2, num3);

    // ----------------------------------------------------------------------------

    num1 = 10, num2 = 6;
    num3 = num1 & num2;
    printf("\nBitwise AND: %d\n", num3);
    num3 = num1 | num2;
    printf("\nBitwise OR: %d\n", num3);
    num3 = num1 ^ num2;
    printf("\nBitwise XOR: %d\n", num3);

    // --------------------------------------------------------------------------------

    return 0;
}
