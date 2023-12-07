#include <stdio.h>

void show(int *a, int *b) {
    ++*a;
    ++*b;
}

int main(void) {
    int a = 10;
    int *ptr = &a;
    int b = a++;
    int d;
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = ++*ptr;     // pre-increment is same as of variables.
    d = *++ptr;    
    printf("\na = %d, b = %d, c = %d, ptr = %p\n", a, b, d, ptr);
    a = 10;
    b = *ptr++;     // In post-increment it increases the pointer address, not actual value.
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    int no = 1198;
    int *p = &no;
    int c = (*p)++;       // To make post-increment happen, this syntax is required.
    printf("\nno = %d, c = %d, p = %p\n", no, c, p);

    // -----------------------------------------------------------------------------

    printf("\n\n************CALL BY REFERENCE***************\n\n");
    int num1 = 10, num2 = 20;
    printf("Before call by reference: num1 = %d, num2 = %d\n", num1, num2);
    show(&num1, &num2);
    printf("After call by reference: num1 = %d, num2 = %d\n\n", num1, num2);
}

