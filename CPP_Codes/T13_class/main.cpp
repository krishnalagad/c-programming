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

float calAvg(int *arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++){
        cout<<arr[i]<<" ";
        sum += arr[i];
    } 
    cout<<endl;
    return sum / 3.0f;
}

void maxAvg(Student *std, int len) {
    float arr[len];
    cout<<endl;
    for (int i = 0; i < len; i++)
        arr[i] = calAvg(std[i].getSubjects(), 3);
    
    cout<<endl;
    float max = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    cout<<"\nMax Avg: "<<max<<endl; 
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

    int arr1[3] = {12,23,34};
    int arr2[3] = {45,56,67};
    int arr3[3] = {12,21,23};
    Student sArr1[3] = {{"Krishna Lagad", 98.23, arr1}, {"Ankita Jogi", 90.23, arr2}, {"Himanshu Wankar", 89.445, arr3}};
    for (int i = 0; i < 3; i++)
        sArr1[i].display();
    maxAvg(sArr1, 3);
    
    return 0;
}