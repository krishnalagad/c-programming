#include <stdio.h>
#include <string.h>

int main()
{
    int size, length;
    printf("Enter size of array and set the approx. max size for each string (size length): ");
    scanf("%d %d", &size, &length);
    char strArr[size][length];

    for (int i = 0; i < size; i++){
        printf("Enter string %d: ", (i + 1));
        char str[length];
        scanf("%s", str);
        strcpy(strArr[i], str);
    }

    for (int i = 0; i < size; i++){
        printf("%s\t", strArr[i]);
    }
    
    return 0;
}
