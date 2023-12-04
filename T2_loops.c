#include <stdio.h>

int main(void)
{
    int num, i, rev = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    for ( i = 1; i <= 10; i++){
        printf("%d  *  %d  =  %d\n", num, i, (num * i));
    }
    
    // printf("\nReverse of number: %d\n\n", rev);
    return 0;
}
