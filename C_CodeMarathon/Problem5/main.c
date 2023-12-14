#include <stdio.h>
#include "header.h"
#include <string.h>

int main(void) {
    int str[10];
    int len;
    printf("Enter string: ");
    scanf("%s", str);
    len = strlen(str);
    solution(str, len);
    // printf("%d", len);
    return 0;
}