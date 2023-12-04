#include <stdio.h>

int main()
{
    int *arr[10]; // array of integer pointers
    int(*p)[6];   // p is pointer to an array
    int x = -10, y = -1;
    if (++y, x)
    {
        printf("Hi\n");
    }
    else
    {
        printf("Byey\n");
    }
    printf("%d\t%d\n", x, y);
    return 0;
}