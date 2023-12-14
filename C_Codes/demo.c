#include <stdio.h>

int main(void)
{
    printf("Hello! This is a test prgoram.\n");
    int num1, num2, i;

    char arr[] = {"Krishna"};

    printf("%s\n", arr);

    for (i = 0; i < 10; i++){
        printf("%d\n", i);
    }
    printf("Enter number1: ");
    scanf("%d", &num1);

    printf("Enter number2: ");
    scanf("%d", &num2);

    printf("Addition is %d", (num1 + num2));
    return 0;
}