#include <iostream>
#include "hospital.h"
#include "doctor.h"

// ------------------Hospital Class-----------------------
Hospital::Hospital(){
    this->id = "ID";
    this->name = "XYZ";
    this->rating = GOOD;
}

Hospital::Hospital(string id, string name, HospitalRating rating){
    this->id = id;
    this->name = name;
    this->rating = rating;
}

Hospital::~Hospital(){
}

//------------------ Docctor class-----------------------------

Doctor::Doctor(){
    this->id = "DID";
    this->name = "NAME";
    this->speciality = "HEART";
    this->docHosName = "XYZ";
    this->fees = 2322.87;
}

Doctor::Doctor(string id, string name, string spe, string docHosName, float fee) {
    this->id = id;
    this->name = name;
    this->speciality = spe;
    this->docHosName = docHosName;
    this->fees = fee;
}

Doctor::~Doctor(){
}

// function usef to calculate tax and return it.
double Doctor::calculateTax(float fee){
    double tx = fee * 0.2;       // 20% tax
    return tx;
}

void Doctor::display() {
    cout<<"\n\nDoctor ID: "<<this->id;
    cout<<"\nDoctor Name: "<<this->name;
    cout<<"\nDoctor Speciality: "<<this->speciality;
    cout<<"\nDoctor Registered hospital name: "<<this->docHosName;
    cout<<"\nDoctor Fees: "<<this->fees;
    cout<<"\nTax: "<<calculateTax(this->fees);
}
