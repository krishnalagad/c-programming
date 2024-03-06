#include <iostream>
#include "theatre.h"
using namespace std;

int main() {
    Theatre t1;
    char ch;
    do{
        cout<<"\n1. Add movie\n2. Book Ticket\n3. Get Movie\n4. Get all\n5. Get Average";
        cout<<"\nEnter your choice: ";
        int choice;
        cin>>choice;
        string name;

        switch (choice){
            case 1:
                t1.addMovie();
                cout<<"\nDo you want to continue: (y/n)";
                getchar();
                cin>>ch;
                break;
            case 2:
                cout<<"\nEnter movie name: ";
                getchar();
                getline(cin, name);
                cout<<"\nEnter movie slot: ";
                int slot;
                cin>>slot;
                t1.bookTicket(name, slot);
                cout<<"\nDo you want to continue: (y/n)";
                getchar();
                cin>>ch;
                break;
            case 3:
                cout<<"\nEnter movie ID: ";
                int id;
                cin>>id;
                t1.getMovie(id);
                cout<<"\nDo you want to continue: (y/n)";
                getchar();
                cin>>ch;
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (ch == 'y');
    
    return 0;
}