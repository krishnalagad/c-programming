#include <stdio.h>

int main(void)
{
    int num1 = 0, num2 = 1, num3, n;
    printf("Enter upper limit of series: ");
    scanf("%d", &n);
    printf("0 1 ");
    for (int i = 0; i < n; i++){
        num3 = num1 + num2;
        printf("%d ", num3);
        num1 = num2;
        num2 = num3;
    }
    printf("\n\n");
    return 0;
}
