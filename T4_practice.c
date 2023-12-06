#include <stdio.h>

int main(void) {
    extern int a;
    a = 20;
    printf("%d\n", sizeof(a));
}
// int a = 20;