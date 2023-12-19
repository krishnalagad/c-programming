#include "header.h"
#include <iostream>
#include <cstring>

static int idCount = 219300;

Student::Student(){
    this->id = idCount;
    idCount++;
    this->name = new char[7 + 1];
    strcpy(this->name, "Default");
    this->marks = new int[MARK_SIZE];
    for (int i = 0; i < MARK_SIZE; i++)
        this->marks[i] = 0;
}

// parameterized constructor
Student::Student(const char *name, int *marks) {
    this->id = idCount++;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->marks = new int[MARK_SIZE];
    for (int i = 0; i < MARK_SIZE; i++)
        this->marks[i] = marks[i];
}

// customised copy constructor
Student::Student(Student &std) {
    this->id = idCount++;   // Not assigning ID of old student, rather assign new one
    this->name = new char[strlen(std.getName()) + 1];
    strcpy(this->name, std.getName());
    this->marks = new int[MARK_SIZE];
    int *temp = std.getMarks();
    for (int i = 0; i < MARK_SIZE; i++)
        this->marks[i] = temp[i];
}

Student::~Student() {
    std::cout<<"Student Obj destroyed!!"<<std::endl;
    delete []name;
    delete []marks;
}

void Student::display() {
    std::cout<<"\nId: "<<this->id<<"\nName: "<<this->name<<std::endl;
    std::cout<<"Marks: ";
    for (int i = 0; i < MARK_SIZE; i++)
        std::cout<<this->marks[i]<<" ";
    std::cout<<std::endl;
}