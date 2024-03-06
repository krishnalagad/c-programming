#include <iostream>
#include "theatre.h"
#include "movieNotFoundException.h"
using namespace std;

Theatre t[120];
static int count = 0;
static int index = 0;
static int idGenerator = 100;
Theatre::Theatre(): id(idGenerator++), name("XYZ"), director("ME"), rating(U), totSeats(100){
    this->casts[0] = "Krishn Lagad";
    this->casts[1] = "Lagad Krishna";
}

Theatre::Theatre(string name, string dir, Rating r, int runtime, string *cast, int seats): id(idGenerator++), name(name), director(dir), rating(r), runtime(runtime), totSeats(seats) {
    this->casts[0] = cast[0];
    this->casts[1] = cast[1];
}

Theatre::~Theatre()
{
}

void Theatre::bookTicket(std::string name, int slot) {
    bool flag = false;
    for (int i = 0; i < 120; i++){
        if(name == t[i].getName()) {
            flag = true;
            if(count < 120) {
                std::cout<<"\nYour Tickets booked for below displayed movie!!";
                std::cout<<t[i];
                count++;
            }
        }
    } 
}

void Theatre::addMovie() {
    if(index < 120) {
        cout<<"\nEnter movie name: ";
        string name;
        cin>>name;
        t[index].setName(name);

        cout<<"\nEnter movie director: ";
        string dir;
        cin>>dir;
        t[index].setDirector(dir);

        cout<<"\nEnter duration: ";
        int run;
        cin>>run;
        t[index].setRuntime(run);

        cout<<"\nEnter total seats: ";
        int s;
        cin>>s;
        t[index].setTotSeats(s);

        string str[2];
        getchar();
        for(int i = 0; i < 2; i++) {
            cout<<"\nEnter cast "<<(i+1)<<": ";
            getline(cin, str[i]);
        }
        t[index].setCasts(str);

        cout<<"\n0 - U, 1 - R, 2 - A\nEnter rating of movie: ";
        int ch;
        cin>>ch;
        switch (ch){
            case 0:
                // this->rating = U;
                t[index].setRating(U);
                break;
            case 1:
                // this->rating = R;
                t[index].setRating(R);
                break;
            case 2:
                // this->rating = U;
                t[index].setRating(A);
                break;
            
            default:
                break;
        }
        index += 1;
    } else {
        cout<<"\nMovie quota fulled!!";
    }
}


void Theatre::getMovie(int id) {
    bool flag = false;
    if(index > 0) {
        for (int i = 0; i < 120; i++){
            if (id == t[i].getId()){
                cout<<t[i];
                flag = true;
                break;
            }
        }
        if(!flag)
            throw MovieNotFoundException();
    } else {
        cout<<"\nMovie database is empty!!";
    }
}
