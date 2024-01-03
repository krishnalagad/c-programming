#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "hospital.h"
using namespace std;

class Doctor {
    private:
        string id;
        string name;
        string speciality;
        string docHosName;
        float fees;
    public:
        Doctor();
        Doctor(string, string, string, string, float);
        ~Doctor();
        void display();

        double calculateTax(float);

        string getId() const { return id; }
        void setId(const string &id_) { id = id_; }

        string getName() const { return name; }
        void setName(const string &name_) { name = name_; }

        string getSpeciality() const { return speciality; }
        void setSpeciality(const string &speciality_) { speciality = speciality_; }

        string getDocHosName() const { return docHosName; }
        void setDocHosName(const string &docHosName_) { docHosName = docHosName_; }

        float getFees() const { return fees; }
        void setFees(float fees_) { fees = fees_; }

        // function usef to calculate tax and return it.
        // double calculateTax(float fee){
        //     double tx = fee * 0.2;       // 20% tax
        //     return tx;
        // }

        friend istream& operator>>(istream& is, Doctor& d) {
            cout<<"\nEnter id: ";
            is>>d.id;
            cout<<"\nEnter name: ";
            is>>d.name;
            cout<<"\nEnter speci: ";
            is>>d.speciality;
            cout<<"\nEnter H Nmae: ";
            is>>d.docHosName;
            cout<<"\nEnter fees: ";
            is>>d.fees;
            return is;
        }

        // friend ostream& operator<<(ostream& os, Doctor& d) {
            // os<<"\nDoctor ID: "<<d.id;
            // os<<"\nDoctor Name: "<<d.name;
            // os<<"\nDoctor Speciality: "<<d.speciality;
            // os<<"\nDoctor Registered hospital name: "<<d.docHosName;
            // os<<"\nDoctor Fees: "<<d.fees;
            // os<<"\nTax: "<<calculateTax(d.fees);
        //     return os;
        // }
};


#endif // DOCTOR_H
