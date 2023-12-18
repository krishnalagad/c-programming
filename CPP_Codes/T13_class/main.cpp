#include <iostream>
#include "Student.h"
using namespace std;

void searchStudentById(Student students[], int len, int id) {
    for (int i = 0; i < len; i++){
        if(id == students[i].getId()){
            cout<<"\nStudent found!!"<<endl;
            break;
        } 
    }
    
}

int main(void){
    // store object in stack
    Student s1;
    s1.display();
    Student s2("Krishna", 90.23);
    s2.display();

    // store array of objects in heap memory
    int size;
    cout<<"\nEnter size: ";
    cin>>size;
    Student *sptr = new Student[size];
    for (int i = 0; i < size; i++){
        sptr[i].setMarks((i+1)*5);
        sptr[i].setName("DefaultName");
    }
    for (int i = 0; i < size; i++)
        sptr[i].display();

    // store array of object in stack
    Student sArr[3] = {{"Krishna", 90.23}, {"ABC", 98.3}, {"PQR", 78.45}};
    for (int i = 0; i < 3; i++)
        sArr[i].display();
    
    searchStudentById(sptr, size, 219308);
    
    return 0;
}