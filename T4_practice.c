#include <stdio.h>

int main(void)
{
    extern int func(float);
    int a;
    a = func(3.14);
    printf("%d\n", a);
    return 0;
}
int func(float num)
// float num;
{
    return ((int)num);
}
// int a = 20;