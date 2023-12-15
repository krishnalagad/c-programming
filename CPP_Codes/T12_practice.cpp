#include <iostream>
#include <cstring>  // string library in C programming
using namespace std;

// << insertion opertor
// >> extraction operator

int main(void) {
    int *arr = new int[10];     // array declaration approach
    char *cptr = new char[20];

    char str[] = "Learning is good";
    int len = strlen(str);
    cout<<"Length of the string is "<<len<<endl;

    int num1, num2;
    cout<<"Enter two numbers: ";
    cin>>num1>>num2;    // cascading effect: taking more than one input from one cin statement.
    cout<<"Addition of two numbers: "<<(num1 + num2)<<endl;

    delete arr, cptr;   // use delete to avoid memory leakage.
    return 0;
}