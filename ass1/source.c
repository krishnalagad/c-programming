#include "header.h"
#include <stdio.h>
#include <string.h>

void chechNumber(int num)
{
    printf("Number is %d", num);
}

void printData(int data)
{
    printf("\nData: %d\n", data);
}

int length(char str[]){
    if (str == NULL)
        return 0;
    int len = strlen(str);
    return len;
}