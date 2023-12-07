#include <stdio.h>

int main(void) {
    int a = 10;
    int *ptr = &a;
    int b = a++;
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = ++*ptr;     // 
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = *ptr++;
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = (*ptr)++;
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
}