#include <iostream>
#include "doctor.h"
#include "hospital.h"
using namespace std;

void displayHos(Hospital *d, int tot, int rating) {
    for (int i = 0; i < tot; i++){
        // HospitalRating rating = static_assert<HospitalRating&>(rating);
        if (rating == d[i].getRating()){
            cout<<"\nId: "<<d[i].getId();
            cout<<"\nName: "<<d[i].getName();
        }
        
    }
    
}

string getHosName(Doctor *d, int tot, string name) {
    for (int i = 0; i < tot; i++){
        if (name == d[i].getName()){
            return d[i].getDocHosName();
        }
    }
    return NULL;
}

float getHighestTax(Doctor *d, int tot) {
    float max = d[0].getFees();
    for(int i = 1; i < tot; i++) {
        if (max < d[i].getFees()){
            max = d[i].getFees();
        }
    }

    return max * 0.2;
}

int main() {
    cout<<"\nEnter total hospital number: ";
    int tot;
    cin>>tot;
    Hospital hosArr[tot];
    for(int i = 0; i < tot; i++)
        cin>>hosArr[i];

    for(int i = 0; i < tot; i++)
        cout<<hosArr[i];

    cout<<"\nEnter total Doctors number: ";
    cin>>tot;
    Doctor docArr[tot];
    for(int i = 0; i < tot; i++)
        cin>>docArr[i];

    for(int i = 0; i < tot; i++)
        docArr[i].display();

    cout<<"\n\nHighest tax: "<<getHighestTax(docArr, tot);
    cout<<"\nEnter Doctor name: ";
    string str;
    getchar();
    getline(cin, str);
    cout<<"\n\nHospital Name: "<<getHosName(docArr, tot, str);

    cout<<"\n\n0 - GOOD, 1 - AVERAGE, 2 - POOR\n\nEnter rating number: ";
    int num;
    cin>>num;
    displayHos(hosArr, tot, num);
    
    return 0;
}