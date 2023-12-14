#include <stdio.h>

int main(void)
{
    int num, year, sellPrice, buyPrice, no;
    char c, ch;
    printf("Enter a number: ");
    scanf("%d", &num);

    // even-odd check
    if (num % 2 == 0)
        printf("Its Even\n");
    else
        printf("Its Odd\n");

    // positive-negtive check
    if(num > 0)
        printf("Its Positive\n");
    else if(num < 0)
        printf("Its Negative\n");
    else
        printf("Its zero\n");

    // leap year check
    printf("Enter year: ");
    scanf("%d", &year);

    if(year % 4 == 0)
        printf("Its Leap Year\n");
    else
        printf("Not leap year\n");

    // profit loss check
    printf("Enter Buying price: ");
    scanf("%d", &buyPrice);
    printf("Enter Selling price: ");
    scanf("%d", &sellPrice);

    if(sellPrice > buyPrice)
        printf("You have made profit of Rs. %d\n", sellPrice - buyPrice);
    else if(sellPrice < buyPrice)
        printf("You are in loss of Rs. %d\n", buyPrice - sellPrice);
    else
        printf("You are neutral\n");

    // ASCII check
    printf("ASCII values of small alphabets are:\n");
    for(c = 'a'; c <= 'z'; c++) {
        printf("%c = %d\t", c, c);
    }
    printf("\n");

    printf("ASCII values of capital alphabets are:\n");
    for(c = 'A'; c <= 'Z'; c++) {
        printf("%c = %d\t", c, c);
    }

    printf("\n");

    // upper lower check
    printf("Enter character:");
    scanf("%c", &ch);
    no = (int)ch;
    // printf("\n%c\n%d\n", ch, no);
    if (no >= 65 && no <= 90)
    {
        printf("Its uppercase alphabet\n");
        printf("Its lowecase is %c\n", (char)no + 32);
    }
    else if (no >= 97 && no <= 122)
    {
        printf("Its lowercase alphabet\n");
        printf("Its uppercase is %c\n", (char)no - 32);
    }
    else
    {
        printf("Please enter an alphabet only");
    }
    return 0;
}
