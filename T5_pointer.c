#include <stdio.h>

int main(void) {
    int a = 10;
    int *ptr = &a;
    int b = a++;
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = ++*ptr;     // pre-increment is same as of variables.
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    a = 10;
    b = *ptr++;     // In post-increment it increases the pointer address, not actual value
    printf("\na = %d, b = %d, ptr = %p\n", a, b, ptr);
    int no = 10;
    int *p = &no;
    int c = (*p)++;       // To make post-increment happen, this syntax is required.
    printf("\nno = %d, c = %d, p = %p\n", no, c, p);
}