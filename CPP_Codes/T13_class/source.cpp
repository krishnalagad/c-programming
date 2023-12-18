#include "Student.h"
// #include "Shapes.h"
#include <iostream>
#include <cstring>
using namespace std;

static int count = 219304;

Student::Student() {
    this->id = count;
    count += 1;
    this->marks = 92.34;
    strcpy(this->name, "Default Name");
}

Student::Student(const char *name, float marks): marks(marks) {
    // this->id = id;
    // this->marks = marks;
    this->id = count;
    count += 1;
    strcpy(this->name, name);
}

Student::Student(const char *name, float marks, int *subjects): marks(marks) {
    this->id = count;
    count += 1;
    strcpy(this->name, name);
    for(int i = 0; i < 3; i++) {
        this->subjects[i] = subjects[i];
    }
}

void Student::display() {
    cout<<"\nID: "<<this->id<<"\nName: "<<this->name<<"\nMarks: "<<this->marks<<endl;
    // cout<<"\nID: "<<this.id<<"\nName: "<<this.name<<"\nMarks: "<<this.marks<<endl;
}

// --------------------------------------------------------------------------------------

// Circle::Circle() {
//     this.radius = 12;
// }

// Circle::Circle(int radius): radius(radius) {

// }