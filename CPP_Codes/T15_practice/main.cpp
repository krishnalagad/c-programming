#include <iostream>
#include "header.h"
#include <cstring>

int main(void) {
    Book b1;
    char ch;
    do{
        std::cout<<"\n1. Add book\n2. Edit book\n3. Search book\n4. View all books\n5. Exit\n";
        
        std::cout<<"\nEnter your choice: ";
        int choice;
        std::cin>>choice;

        switch (choice){
            case 1:
                std::cout<<"\nEnter book name: ";
                char bookName[50];
                // std::cin>>bookName;
                getchar();
                std::cin.getline(bookName, 50);

                std::cout<<"Enter total pages: ";
                int size;
                std::cin>>size;

                b1.acceptData(bookName, size);

                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 2:
                std::cout<<"\nEnter book Id: ";
                int id;
                std::cin>>id;

                b1.modifyBook(id);

                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 3:
                std::cout<<"\nEnter book Id: ";
                int tempId;
                std::cin>>tempId;

                b1.searchBook(tempId);

                std::cout<<"\nDo you want to continue (y/n): ";
                std::cin>>ch;
                break;
            case 4:
                b1.displayAll();
                break;
            case 5:
                ch == 'n';
                break;
            default:
                break;
        } 
    } while (ch == 'y');
    
    return 0;
}

