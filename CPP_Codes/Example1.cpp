#include <iostream>
using namespace std;

class Triangle {
    private:
        double base = 5.8;
        double height;
    public:
        double calculateArea() {
            return 0.5 * 5.0f * base;
        }
        Triangle(){}
        Triangle(double b, double h) {
            
        }
        ~Triangle(); 
};
Triangle::~Triangle() {
    cout<<"destroyed\n";
}
int main(){
    Triangle t1, t2, t3, t4;
    Triangle *tPtr = new Triangle[3];
    
    cout<<t1.calculateArea()<<endl;
    delete []tPtr;
    return 0;
}