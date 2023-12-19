/*
    class Product{
        char *name;
    }
    Product p1("Hello");
    Product p2("Krishna");
    Product p3 = p1 + p2;
*/

#include <iostream>
#include <cstring>
using namespace std;

class Product {
    char *name;
    public:
        Product(): name(nullptr){}
        Product(char *name) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        ~Product() {
            delete []name;
        }

        char *getName() const { return name; }
        void setName(char *name_) { 
            delete []name;  // delete existing memory if present.
            this->name = new char[strlen(name_) + 1];
            strcpy(this->name, name_); 
        }  

        Product operator+(Product &product) {
            Product temp;
            temp.name = new char[strlen(this->name) + strlen(product.name) + 1];
            strcpy(temp.name, this->name);
            strcat(temp.name, product.name);
            return temp;
        } 
        friend void operator<<(ostream &os, const Product &product) {
            os<<"\n"<<product.getName()<<endl;
        }
};

int main(void) {
    Product p1("Hello");
    Product p2("Krishna");
    Product p3 = p1 + p2;
    cout<<p3;
    return 0;
}