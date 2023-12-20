#include <iostream>
#include <cstring>  // string library from C programming
#include <string>   // string library in C++ programming
using namespace std;

// << insertion opertor
// >> extraction operator
// poiters are flexible whereas references are rigid.
// We can return global variable by reference, but cant local variable.(gives warning)
// Unlike pointer, References has to be initilize on the same line.
// Unlike pointer, Array of references is not allowed.
// structure in C++ can contain functions also.

void fun(int &a) {    // reference
    a += 2;
}

void fun(int *a) {
    int x;
    const int *const ptr = &x;  // constant pointer to constant data (integer)
    *a += 10;
}

int main(void) {
    int a = 20;
    fun(&a);
    cout<<a<<endl;

    int *arr = new int[10];     // array declaration approach
    char *cptr = new char[20];
    int *scores = new int[10];

    char str[] = "Learning is good";
    int len = strlen(str);
    cout<<"Length of the string is "<<len<<endl;

    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;    // cascading effect: taking more than one input from one cin statement.
    cout<<"Addition of two numbers: "<<(num1 + num2)<<endl;

    delete arr, cptr;   // use delete to avoid memory leakage.
    delete []scores;    // delete all the array not only 1st block of it.
    return 0;
}