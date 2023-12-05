#include <stdio.h>
#include <string.h>

int main(void)
{
    // String length
    int len1, len2;
    char arr1[] = {"Krishna"};
    char arr2[] = {'k', 'r', 'i', 's', 'h', 'n', 'a', '\0'};    // add null terminator in this types 

    len1 = strlen(arr1);
    len2 = strlen(arr2);

    printf("length1: %d\nlength2: %d\n\n", len1, len2);

    // String split
    printf("Enter String: ");
    char str[] = "Hello World How Are You";
    // scanf("%s", str);
    const char delimiter[] = " ";

    char *token = strtok(str, " ");     // Use strtok to tokenize the string

    while (token != NULL) {     // Loop through the tokens and print them
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
    printf("\n");

    // String split: Thread-safe
    char str1[] = {"krishna lagad is my name."};
    char *savePtr;

    char *tokens1 = strtok_r(str1, " ", &savePtr);
    while (tokens1 != NULL) {
        int len = strlen(tokens1);
        printf("%s\t%d\n", tokens1, len);
        tokens1 = strtok_r(NULL, " ", &savePtr);
    }
    printf("\n");

    // String compare
    char str3[] = {"krishna"};
    char str2[] = {"lagad"};
    int len = strcmp(str3, str2);
    printf("Comparision: %d\n", len);

    

    return 0;
}
