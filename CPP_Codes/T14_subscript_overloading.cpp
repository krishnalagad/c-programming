#include <iostream>
#include <cstring>

class Employee{
    private:
        char name[20];
    public:
        Employee(){strcpy(this->name, "Abhishek");}
    
    // subscript overloading
    char operator[](int index) {
        return this->name[index];
    }
};

int main(void){
    Employee e1;
    char ch = e1[0];
    std::cout<<ch<<std::endl;
    return 0;
}
