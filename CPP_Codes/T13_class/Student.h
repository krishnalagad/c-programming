#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

class Student{
    private:
        int id;
        char name[30];
        float marks;
        int subjects[3];
    public:
        Student();
        Student(const char *, float);
        Student(const char *, float, int *);
        void display();

        float getMarks() { return marks; }
        void setMarks(float marks_) { marks = marks_; }

        char * getName() { return name; }
        void setName(char *name_) { strcpy(this->name, name_); }

        int getId() { return id; }
        void setId(int id_) { id = id_; }

        int * getSubjects() { return subjects; }
        void setSubjects(int *subjects_) { 
            for (int i = 0; i < 3; i++)
                this->subjects[i] = subjects[i];
        }
};

#endif // STUDENT_H
