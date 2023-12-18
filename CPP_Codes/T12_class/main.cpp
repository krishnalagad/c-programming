#include <iostream>
#include "Student.h"

int main(void){
    Student s1;
    s1.display();
    Student s2(100, "Krishna", 90.23);
    s2.display();
    return 0;
}
