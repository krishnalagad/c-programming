#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, i, rev = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    while (num > 0)
    {
        int rem = num % 10;
        rev = (rev * 10) + rem;
        num /= 10;
    }
    printf("\nReverse of number: %d\n\n", rev);
    return 0;
}
