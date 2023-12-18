#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student{
    private:
        int id;
        char name[30];
        float marks;
    public:
        Student();
        Student(const char *, float);
        void display();

        float getMarks() { return marks; }
        void setMarks(float marks_) { marks = marks_; }

        char * getName() { return name; }
        void setName(char *name_) { strcpy(this->name, name_); }

        int getId() { return id; }
        void setId(int id_) { id = id_; }
};

#endif // STUDENT_H
