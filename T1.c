#include <stdio.h>

int main()
{
    // int *arr[10]; // array of integer pointers
    // int(*p)[6];   // p is pointer to an array
    // int x = -10, y = -1;
    int a = 4;
    int b = ++a * a++ * a++;
    int c = a;
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    // ------------------------------------------------------------------

    int arr[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < sizeof(arr) / 4; i++){
        printf("%d\t", *ptr);
        sum += *ptr++;
    }
    printf("\n%d\n", sum);
    printf("%d %d %d\n", sum++, sum++, sum++);

    // -----------------------------------------------------------------------

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
    
    return 0;
}