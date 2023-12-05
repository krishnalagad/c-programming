#include <stdio.h>
#include <string.h>

int main(void) {
    char *strArr[] = {"Krishna", "Dilip", "Lagad"};
    
    for (int i = 0; i < 3; i++)
    {
        printf("%s\t", strArr[i]);
    }
    
}