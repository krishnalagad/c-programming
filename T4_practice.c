#include <stdio.h>

int main(void) {
    extern int fun(float);
    int a;
    a = fun(3.14);
    printf("%d\n", a);
}
int fun(float num)
// float num;
{
    return ((int) num);
}
// int a = 20;