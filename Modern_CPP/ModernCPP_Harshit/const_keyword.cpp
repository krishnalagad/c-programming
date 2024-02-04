#include <iostream>

//const correctness!
 
/*
 
    rule 1: const gets applied on token to its immediate left. 
    If there is no token on the left, it is applied to the token 
    on its immediate right

    rule 2: pointer symbol * is also considered a token

*/

class Employee {
    private:
        int _id;
    public:
        Employee(/* args */) {}
        ~Employee() {}
};
 
int main() {
 
    //type 1; const with a non-pointer primitive variable
    const int n1=10; //n1 is a "constant integer"
    int const n2=20; //n2 is a "contant integer"

    // type 2: const with a pointer variable of any type
    const char * cptr1 = new char('K');     // cptr1 is a pointer to a constant char
    // *cptr1 = 'B';  // error: cannot change data cuz constant character

    char * const cptr2 = new char ('K');    // cptr2 is a constant pointer to regular char
    *cptr2 = 'L';     // is ok, because pointer is constant not char
    // cptr2 = &ch;     // is not ok

    int n1 = 110;
    const int * const iPtr = &n1;   // iPtr is constant pointer to constant integer

    // type 3: const on a object (reference-type/user-defined types)
    const Employee e1();    // e1 is now constant, can't modify any data value from the object

    // type 4: const member functions
    /*
        these are functions which are "safe" for constant objects.
        constat objects are only allowed to call member functions 
        which are marked as const
    */

    return 0;
}