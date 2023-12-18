#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student() {
    this->id = 1;
    this->marks = 92.34;
    strcpy(this->name, "Default Name");
}

Student::Student(int id, const char *name, float marks) {
    this->id = id;
    this->marks = marks;
    strcpy(this->name, name);
}

void Student::display() {
    cout<<"\nID: "<<this->id<<"\nName: "<<this->name<<"\nMarks: "<<this->marks<<endl;
    // cout<<"\nID: "<<this.id<<"\nName: "<<this.name<<"\nMarks: "<<this.marks<<endl;
}

// --------------------------------------------------------------------------------------

Circle::Circle() {
    this.radius = 12;
}

Circle::Circle(int radius) {
    this.radius = radius;
}