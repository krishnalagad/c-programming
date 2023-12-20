#include <iostream>
#include "header.h"
// using namespace std;

int main(){
    Student s1;
    s1.display();

    int marks1[3] = {98, 67, 89};
    Student s2("Krishna", marks1);
    s2.display();

    int size = 3;
    Student *sPtr = new Student[size];
    for (int i = 0; i < size; i++) {
        int marks2[3] = {89+i, 56+i, 99-i};
        sPtr[i].setName("Jack Reacher");
        sPtr[i].setMarks(marks2);
    }

    for (int i = 0; i < size; i++)
        sPtr[i].display();

    Student s3 = s2;
    s3.display();
    
    delete []sPtr;
    
    return 0;
}
