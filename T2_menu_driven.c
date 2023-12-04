#include <stdio.h>

int main(void)
{
    int num1, num2, choice, ans;
    char ch;

    do
    {
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n\n");
        printf("Enter your choise: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number 1: ");
            scanf("%d", &num1);
            printf("Enter number 2: ");
            scanf("%d", &num2);
            ans = num1 + num2;
            printf("Addition is %d ", ans);

            printf("\nDo you want to continue (y/n): ");
            scanf("%c", &ch);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            ch = 'n';
            break;
        default:
            printf("Please enter correct choice");
            break;
        }
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
