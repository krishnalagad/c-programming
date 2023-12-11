#include <stdio.h>

struct T8_practice
{
    int marks[5];
}stud;


int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    typedef struct T8_practice Student;
    Student s1;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
        stud.marks[i] = arr[i];

    for (int i = 0; i < len; i++)
        printf("Value: %d\n", stud.marks[i]);   
}