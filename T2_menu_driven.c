#include <stdio.h>

int main(void)
{
    int num1, num2, choice, ans;
    char ch = 'y';

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
            scanf(" %c", &ch);
            printf("\n");
            break;
        case 2:
            printf("Enter number 1: ");
            scanf("%d", &num1);
            printf("Enter number 2: ");
            scanf("%d", &num2);
            ans = num1 - num2;
            printf("Substraction is %d ", ans);

            printf("\nDo you want to continue (y/n): ");
            scanf(" %c", &ch);
            printf("\n");
            break;
        case 3:
            printf("Enter number 1: ");
            scanf("%d", &num1);
            printf("Enter number 2: ");
            scanf("%d", &num2);
            ans = num1 * num2;
            printf("Multiplication is %d ", ans);

            printf("\nDo you want to continue (y/n): ");
            scanf(" %c", &ch);
            printf("\n");
            break;
        case 4:
            printf("Enter number 1: ");
            scanf("%d", &num1);
            printf("Enter number 2: ");
            scanf("%d", &num2);
            if (num2 == 0){
                printf("\n Can't perfrom division by zero\n\n");
                break;
            } else {
                ans = num1 / num2;
            }
            printf("Division is %d ", ans);

            printf("\nDo you want to continue (y/n): ");
            scanf(" %c", &ch);
            printf("\n");
            break;
        case 5:
            ch = 'n';
            printf("\nExiting application, Bye !\n\n");
            break;
        default:
            printf("Please enter correct choice\n\n");
            break;
        }
    } while (ch == 'y' || ch == 'Y');

    return 0;
}
