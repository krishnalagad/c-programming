#include <stdio.h>
#include "header.h"

extern void printData(int data);

int main()
{
    chechNumber(100);
    printData(200);
    char str[] = {"Krishna"};
    int len = length(str);
    printf("\nLength: %d\n", len);

    // date validator
    int day, month, year;
    printf("Enter date in this format (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    if (isValidDate(day, month, year)){
        printf("Date is valid\n");
    }else{
        printf("Date is not valid\n");
    }
    
    return 0;
}
