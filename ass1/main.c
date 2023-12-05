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
    return 0;
}
