#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num, i, rev = 0;
    bool flag = false;
    printf("Enter number: ");
    scanf("%d", &num);
    for (i = 2; i < num - 1; i++){
        if (num % i == 0){
            flag = true;
            break;
        }   
    }
    if (!flag)
        printf("\nPrime number\n");
    else
        printf("Non Prime number\n");
    
    return 0;
}
