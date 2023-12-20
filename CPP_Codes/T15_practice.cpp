#include <iostream>
using namespace std;

class Payment{
private:
    int val;
public:
    Payment(/* args */){}
    void pay(){
        cout<<"\nPay()\n";
    }
};

int main(void){
    Payment *ptr = new Payment;
    (*ptr).pay();
    return 0;
}