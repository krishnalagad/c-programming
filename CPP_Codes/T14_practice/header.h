#ifndef HEADER_H
#define HEADER_H

#include <cstring>
#define MARK_SIZE 3

class Student{
    private:
        int id;
        char *name;
        int *marks;
    public:
        Student();
        Student(const char *, int *);
        Student(Student &std);  // copy constructor
        ~Student();

        void display();

        int getId() { return id; }
        void setId(int id_) { id = id_; }

        char *getName()  { return name; }
        void setName(char *name_) { 
            delete []name;
            this->name = new char(strlen(name_) + 1);
            strcpy(this->name, name_);
        }     

        int *getMarks() { return marks; }
        void setMarks(int *marks_) { 
            delete []marks;
            this->marks = new int[MARK_SIZE];
            for (int i = 0; i < MARK_SIZE; i++){
                this->marks[i] = marks_[i];
            } 
        }
};

#endif // HEADER_H
