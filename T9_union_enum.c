#include <stdio.h>

enum Category{
    PRIMARY,
    HIGHER
};

union Performnce {
    char grade;
    float percentage;
};

typedef struct Student {
    char name[30];
    int marks[3];
    enum Category sType;
    union Performnce pf;
} Std;



void display(Std s) {
    printf("Name: %s\n", s.name);
    printf("Marks: ");
    for(int i = 0; i < 3; i++) {
        printf("%d, ", s.marks[i]);
    }
    switch (s.sType)
    {
    case PRIMARY:
        printf("Grade: %c\n", s.pf.grade);
        break;
    case HIGHER:
        printf("Percentage: %f\n", s.pf.percentage);
        break;
    default:
        break;
    }
}

int main(void) {
    Std s1;
    printf("Enter name of Student: ");
    scanf("%[^\n]s", s1.name);
    for(int i = 0; i < 3; i++) {
        printf("Enter mark of subject %d: ", (i + 1));
        scanf("%d", &s1.marks[i]);
    }
    printf("Enter category (0 - PRIMAARY, 1 - HIGHER): ");
    scanf("%d", &s1.sType);

    if(s1.sType == PRIMARY) {
        printf("Enter grade: ");
        scanf(" %c", &s1.pf.grade);
    }
    if(s1.sType == HIGHER) {
        printf("Enter percentage: ");
        scanf(" %f", &s1.pf.percentage);
    }

    display(s1);
    return 0;
}