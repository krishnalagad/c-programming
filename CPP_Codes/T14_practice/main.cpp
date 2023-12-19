#include <iostream>
#include "header.h"
// using namespace std;

int main(){
    Student s1;
    s1.display();

    Student s2("Krishna");
    s2.display();

    int size = 2;
    Student *sPtr = new Student[size];
    for (int i = 0; i < size; i++) 
        sPtr[i].setName("Jack Reacher");
    
    for (int i = 0; i < size; i++)
        sPtr[i].display();

    Student s3 = s2;
    s3.display();
    
    delete []sPtr;
    
    return 0;
}
