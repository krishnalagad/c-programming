#include <stdio.h>

struct T8_practice
{
    int marks[5];
}stud;  // default value is 0

struct Employee{
    int empId;
    char name[30];
    double salary;
};


void acceptData(struct Employee *ptr) {
    printf("Enter ID: ");
    scanf("%d", &ptr->empId);
    printf("Enter name: ");
    scanf(" %[^\n]s", ptr->name);
    printf("Enter salary: ");
    scanf("%lf", &ptr->salary);
}

void display(struct Employee emp) {
    printf("\nEmployee Details\n");
    printf("Id: %d\n", emp.empId);
    printf("Name: %s\n", emp.name);
    printf("Salary: %lf\n", emp.salary);
}

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    typedef struct T8_practice Student;
    Student s1;     // default value is garbage 
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
        stud.marks[i] = arr[i];

    for (int i = 0; i < len; i++)
        printf("Value: %d\t", stud.marks[i]); 
    printf("\n");

    // -----------------------------------------------------------------------------------

    struct Employee employee;
    acceptData(&employee);
    display(employee);

}