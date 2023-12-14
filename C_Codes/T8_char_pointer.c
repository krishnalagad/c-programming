#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char **ptr = NULL;
    int no;
    printf("How many strings you want to store: ");
    scanf("%d", &no);
    ptr = (char**) malloc(no * sizeof(char*));

    for (int i = 0; i < no; i++){
        char temp[40];
        printf("Enter String: ");
        scanf(" %[^\n]s", temp);
        ptr[i] = (char*) malloc((strlen(temp) + 1)* sizeof(char));
        strcpy(ptr[i], temp);
    }
    printf("\n");
    for (int i = 0; i < no; i++){
        printf("%s\n", ptr[i]);
    }
    printf("\n");
    
    return 0;
}