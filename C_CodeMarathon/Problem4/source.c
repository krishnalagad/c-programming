#include <stdio.h>
#include "header.h"

// get the digit counts of start and end to validate in main.c
int getDigitCount(int num) {
    int count = 0, rem;
    while (num > 0){
        rem = num % 10;
        count++;
        num /= 10;
    }
    return count;
}

int solution(int start, int end) {
    int digitArr[10] = {0};     // size 10 because numbers consist of 0 to 9 only, so total is 10
    for (int i = start; i <= end; i++){
        int temp = i;
        int rem;
        while (temp != 0){
            digitArr[temp % 10]++;  // % 10 gives last digit of number and make increment in digit array
            temp /= 10;
        }
    }  

    // initially assign 0th value in array as max and run array from 1st index
    int maxCount = digitArr[0];
    int maxDigit = 0;

    // check for maximum occurance and its respective digit, if it present replace it with previous max.
    for(int i = 1; i < 10; i++) {
        if (digitArr[i] > maxCount){
            maxCount = digitArr[i];
            maxDigit = i;
        }
    }

    // printf("\nHence the maximum frequency found within the range %d to %d is digit %d. \nHence output is %d and its frequency is %d\n\n", start, end, maxDigit, maxDigit, maxCount);
    return maxDigit;
}