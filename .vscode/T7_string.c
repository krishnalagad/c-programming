#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    char str[10];   // constant pointer to non constant string
    printf("Enter string: ");
    gets(str);
    printf("%s\n", str);

    char *p = "krishna";        // only allowed for string. non constant pointer to constant string
    printf("%s\n", p);

    char *ch = malloc(10 * sizeof(char));   // non constant pointer to non constant string.
    printf("Enter string: ");
    gets(ch);
    printf("%s\n", ch);

    char arr[7] = "KPIT";
    printf("arr: %s\n", arr);

    char *ptr = arr;
    printf("ptr: %s\n", ptr);

    printf("%c\n", ++*ptr);
    printf("++*ptr: %s\n", arr);

    printf("%c\n", *++ptr);
    printf("*++ptr: %s\n", arr);

    printf("%c\n", *ptr++);
    printf("*ptr++: %s\n", arr);

    printf("%c\n", (*ptr)++);
    printf("(*p)++: %s\n", arr);

    return 1;
}