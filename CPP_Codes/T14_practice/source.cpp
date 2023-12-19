#include "header.h"
#include <iostream>
#include <cstring>
// using namespace std;

static int idCount = 219300;

Student::Student(){
    this->id = idCount;
    idCount++;
    this->name = new char[7 + 1];
    strcpy(this->name, "Default");
}

Student::Student(const char *name) {
    this->id = idCount++;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// customised copy constructor
Student::Student(Student &std) {
    this->id = idCount++;   // Not assigning ID of old student, rather assign new one
    this->name = new char[strlen(std.getName()) + 1];
    strcpy(this->name, std.getName());
}

Student::~Student() {
    std::cout<<"Student Obj destroyed!!"<<std::endl;
    delete []name;
}

void Student::display() {
    std::cout<<"\nId: "<<this->id<<"\nName: "<<this->name<<std::endl;
}