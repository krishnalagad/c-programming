#include <stdio.h>
#include "header.h"
#include <string.h>
 
// function to check string is palindrome or not.
void checkPalindrome(char *str, int start, int end) {
    int flag = 1;
    while (start < end){
        
        if (str[start] != str[end]){    // if start &  end char is not same, not pallindrome, break loop
            start++;
            end--;  
        }
        checkPalindrome(str, start, end);
    }
    // start++;
    // end--;
    for (int i = start; i <= end; i++){
        printf("%c", str[i]);
    }
    
    // return flag;
}

void solution(char *str, int len) {

    int start = 0;
    int end = len - 1;
    checkPalindrome(str, start, end);
    // int res = checkPalindrome(str, start, len);
    

    // char ch1[3];
    // char ch2[3];
    //    for (int i = 2; i < len; i++){
    //         ch1[0] = str[i - 2];
    //         ch1[1] = str[i - 1];
    //         ch1[2] = str[i];

    //         ch2[0] = str[i];
    //         ch2[1] = str[i - 1];
    //         ch2[2] = str[i - 2];
    //         printf("\nResult str: %s\n", ch1);
    //         printf("\nResult str: %s\n", ch1);
    //         str
    //         int res = strcmp(ch1, ch2);
    //         if (strcmp(ch1, ch2) == 1){
    //             printf("Palindrome: %c%c%c\n\n", str[i-2], str[i-1], str[i]);
    //             break;
    //         }
    //    }
    //    for(int i = 2; i < len; i++) {
    //         char *ch3 = str[i-2] + str[i-1];
    //         char *ch4 = str[i - 1] + str[i-2];
    //         if (strcmp(ch3, ch4)){
    //             printf("Palindrome: %c%c\n\n", str[i-2], str[i-1]);
    //             break;
    //         }
    //    }
    //    printf("\nNo Palindrome Found\n");
       
}


// solution inner block:
    // int temp = len - 1;
    // int finalFlag = 1;
    // int start = 0;
    // while (temp > 0){
    //     int flag = checkPalindrome(str, temp);
    //     if (flag){
    //         for (int i = 0; i <= temp; i++){
    //             printf("%c", str[i]);
    //         }
    //         printf("\t");
    //         break;
    //     } else {
    //         finalFlag = 0;
    //         temp -= 1;
    //     }
    // }
    // while (start < len){
    //     int flag = checkPalindrome(str, start);
    //     if (flag){
    //         for (int i = start; i < len; i++){
    //             printf("%c", str[i]);
    //         } 
    //         printf("\t");
    //         break;
    //     } else {
    //         finalFlag = 0;
    //         start += 1;
    //     }
    // } 