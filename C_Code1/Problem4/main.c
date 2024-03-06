#include <stdio.h>
#include "header.h"

int main(void) {
    int start, end;
    printf("Start value: ");
    scanf("%d", &start);
    printf("End value: ");
    scanf("%d", &end);

    int digits1, digits2, ans;
    digits1 = getDigitCount(start);
    digits2 = getDigitCount(end);
    if (digits1 > 3 || digits2 > 3){    // validation check: digits should not exceed 3
        printf("\nNumbers with more than 3 digits are not acceptable. Please enter valid values.\n\n");
        return 0;
        // main();
        // printf("Start value: ");
        // scanf("%d", &start);
        // printf("End value: ");
        // scanf("%d", &end);
    }
    if (start < 0 || end <= 0){    // vlidation check: numbers should not be negative
        printf("\nNegtive integer in not acceptable. Please enter valid values.\n\n");
        return 0;
        // main();
        // printf("Start value: ");
        // scanf("%d", &start);
        // printf("End value: ");
        // scanf("%d", &end);
    }
    if (start > end){  // validation check: start should not exceed end
        printf("\nStart value should not exceed end value. Please enter valid values.\n\n");
        return 0;
        // main();
        // printf("Start value: ");
        // scanf("%d", &start);
        // printf("End value: ");
        // scanf("%d", &end);
    } 
        ans = solution(start, end);
    
    printf("\nHence the maximum frequency found within the range %d to %d is digit %d. \nHence output is %d\n\n",start, end, ans, ans);

    return 0;
}
