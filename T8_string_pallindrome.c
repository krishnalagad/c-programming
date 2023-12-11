#include <stdio.h>
#include <string.h>

int isPalindrome(char *str, int start, int end) {
    int flag = 1;
    while (start < end){
        if (str[start] != str[end]) {
            flag = 0;  // Not a palindrome
            break;
        }
        start++;
        end--;
    }
    return flag;
    
}
int getPallindromeCount(char *arr) {
    int count = 0;
    if (arr == NULL)
        return 0;
    char *token = strtok(arr, " ");
    while (token != NULL) {
        int start = 0;
        int end = strlen(token) - 1;  
        int flag = isPalindrome(token, start, end);
        if (flag)
            count += 1;
        token = strtok(NULL, " ");
    }
    return count;
}

int main(void) {
    char str[] = {"Hello kaka nayan madam meet"};
    int result = getPallindromeCount(str);
    printf("Count: %d\n", result);
    return 0;
}