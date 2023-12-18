#include <iostream>

class Student{
    private:
        int id;
        char name[30];
        float marks;
    public:
        Student();
        Student(int, const char *, float);
        void display();
};

