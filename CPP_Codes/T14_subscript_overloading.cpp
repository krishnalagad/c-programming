#include <iostream>
#include <cstring>

class Employee{
    private:
        char name[20];
    public:
        Employee(){strcpy(this->name, "Abhishek");}
        void display() {
            std::cout<<name<<std::endl;
        }
    
        // subscript overloading

        // char operator[](int index) {
        //     return this->name[index];
        // }
        char& operator[](int index) {
            if(!(index>=0 && index < strlen(name)))
                throw "Index out of bound";
            return this->name[index];
        }
};

int main(void){
    Employee e1;
    try{
        char ch = e1[0];
        std::cout<<ch<<std::endl;
    }
    catch(const char *msg){
        std::cout<<"\n"<<msg<<std::endl;
    }
    
    e1[1] = 'a';
    e1.display();
    return 0;
}
