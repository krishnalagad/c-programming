#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[30];
}S;

typedef struct Address {
    int pinCode;
    char city[20];
    char state[20];
}A;

void acceptData(S *s, int len) {
    for (int i = 0; i < len; i++){
        printf("Enter Id of Student %d: ", (i + 1));
        scanf(" %d", &s[i].id);
        getchar();
        printf("Enter name of Student %d: ", (i + 1));
        scanf(" %s", s[i].name);
    } 
}

void display(S *s, int len) {
    for (int i = 0; i < len; i++){
        printf("Id of Student %d: %d\n",(i + 1), s[i].id);
        printf("Name of Student %d: %s\n\n",(i + 1), s[i].name);
    } 
}

int main(void) {
    int size;
    printf("Enter total number of students: ");
    scanf("%d", &size);
    S *s = (S*) malloc(size * sizeof(S));
    acceptData(s, size);
    display(s, size);
}