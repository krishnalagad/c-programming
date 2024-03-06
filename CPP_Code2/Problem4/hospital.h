#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>
using namespace std;

class Hospital {
    public:
        enum HospitalRating{GOOD, AVERAGE, POOR};
    private:
        string id;
        string name;
        HospitalRating rating;

    public:
        Hospital();
        Hospital(string, string, HospitalRating);
        ~Hospital();

        string getId() const { return id; }
        void setId(const string id_) { id = id_; }

        string getName() const { return name; }
        void setName(const string name_) { name = name_; }

        HospitalRating getRating() const { return rating; }
        void setRating(const HospitalRating &rating_) { rating = rating_; }

        friend istream& operator>>(istream& is, Hospital& h) {
            cout<<"\nEnter Hos Id: ";
            is>>h.id;
            cout<<"\nEnter Name: ";
            is>>h.name;
            cout<<"\n\n0 - GOOD, 1 - AVERAGE, 2 - POOR\nEnter your revie: ";
            int choice;
            is>>choice;
            switch (choice){
            case 0:
                h.setRating(GOOD);
                break;
            case 1:
                h.setRating(AVERAGE);
                break;
            case 2:
                h.setRating(POOR);
                break;
            
            default:
                break;
            }

            return is;

        }

        friend ostream& operator<<(ostream& os, Hospital& h) {
            os<<"\n";
            os<<"\nHos Id: "<<h.id;
            os<<"\nHos Name: "<<h.name;
            os<<"\nHos Rating: ";
            switch(h.rating) {
                case 0:
                    os<<"GOOD";
                    break;
                case 1:
                    os<<"AVERAGE";
                    break;
                case 2:
                    os<<"POOR";
                    break;
            }
            return os;
        }
};

#endif // HOSPITAL_H
