#include <iostream>
#include <cstring>
#include "book.h"

int main(void) {
    Book b1;
    for (int i = 0; i < BOOK_SIZE; i++){
        std::cout<<"\nEnter name of book :";
        char bookName[50];
        getchar();
        std::cin.getline(bookName, 50);

        std::cout<<"Enter author name: ";
        char authorName[50];
        // getchar();
        std::cin.getline(authorName, 50);

        std::cout<<"Enter price: ";
        int price;
        std::cin>>price;

        std::cout<<"Enter number of days: ";
        int days;
        std::cin>>days;

        b1.accept(bookName, authorName, price, days);
    }
    std::cout<<"\n-------------------ALL BOOKS------------------------\n\n";
    b1.display();
    std::cout<<"\n-------------------BOOKS WITH AUTHOR NAME STARTS WITH A------------------------\n\n";
    b1.displayNamesStartWithA('A');
    std::cout<<"\n-------------------BOOKS WITH PRICE LESS THAN 2500RS.------------------------\n\n";
    b1.displayBooksLowerThan2500();
}