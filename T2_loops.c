#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i, sum = 0;
    for ( i = 0; i <= 10; i++)
    {
        sum += i;
    }

    sum = 10 * (10 + 1) / 2;
    printf("%d", sum);
    return 0;
}
