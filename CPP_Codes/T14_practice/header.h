#ifndef HEADER_H
#define HEADER_H

#include <cstring>

class Student{
    private:
        int id;
        char *name;
    public:
        Student();
        Student(const char *);
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
};

#endif // HEADER_H
