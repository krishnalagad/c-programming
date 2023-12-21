#include <iostream>
#include <cstring>
#include "book.h"

static int idGenerator = 100;
int fineAmt = 0;
Book books[BOOK_SIZE];
static int count = 0;

Book::Book(){
    this->bookId = idGenerator++;
    this->price = 500;
    this->numberOfDaysUsed = 30;
    strcpy(this->authorName, "Krishna");
    strcpy(this->bookName, "Sleeping murder");
}

Book::Book(char *name, char *author, int price, int days) {
    this->bookId = idGenerator++;
    this->price = price;
    this->numberOfDaysUsed = days;
    strcpy(this->authorName, author);
    strcpy(this->bookName, name);
}

void Book::display() {
    for (int i = 0; i < BOOK_SIZE; i++){
            // std::cout<<"\nBook Id: "<<this->bookId<<"\nBook Name: "<<this->bookName<<"\nAuthor Name: "<<this->authorName<<"\nPrice: "<<this->price<<"\nNumber of Days: "<<this->numberOfDaysUsed<<"\nFine: "<<this->calculateFine(this->numberOfDaysUsed)<<std::endl;
        std::cout<<"\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nAuthor Name: "<<books[i].getAuthorName()<<"\nPrice: "<<books[i].getPrice()<<"\nNumber of Days: "<<books[i].getNumberOfDaysUsed()<<"\nFine: "<<this->calculateFine(books[i].getNumberOfDaysUsed())<<std::endl;
    }  
}

int Book::calculateFine(int days) {
    if(days <= 10) {
        fineAmt = 0;
        return fineAmt;
    }
    if (days > 10 && days <= 20) {
        fineAmt = 100;
        return fineAmt;
    } else if(days > 20 && days <= 30) {
        fineAmt = 200;
        return fineAmt;
    } else if (days > 30 && days <= 40) {
        fineAmt = 300;
        return fineAmt;
    } else {
        fineAmt = 400;
        return fineAmt;
    }   
}

void Book::accept(char *bookName, char *authorName, int price, int days) {
    if(count < 3) {
        books[count].setBookId(idGenerator++);
        books[count].setAuthorName(authorName);
        books[count].setBookName(bookName);
        books[count].setPrice(price);
        books[count].setNumberOfDaysUsed(days);
        count++;
    } else {
        std::cout<<"Book quota is filled!!";
    }
}

void Book::displayNamesStartWithA(char ch){
    int count = 0;
    for (int i = 0; i < BOOK_SIZE; i++){
        // char name[50] = books[i].getAuthorName();
        if(ch == books[i].authorName[0]) {
            std::cout<<"\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nAuthor Name: "<<books[i].getAuthorName()<<"\nPrice: "<<books[i].getPrice()<<"\nNumber of Days: "<<books[i].getNumberOfDaysUsed()<<"\nFine: "<<this->calculateFine(books[i].getNumberOfDaysUsed())<<std::endl;
            count += 1;
        } 
    }
    if (count == 0){
        std::cout<<"No books available with the name start with A"<<std::endl;
    }
    
}

void Book::displayBooksLowerThan2500() {
    int count = 0;
    for (int i = 0; i < BOOK_SIZE; i++){
        if (books[i].getPrice() < 2500){
            std::cout<<"\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nAuthor Name: "<<books[i].getAuthorName()<<"\nPrice: "<<books[i].getPrice()<<"\nNumber of Days: "<<books[i].getNumberOfDaysUsed()<<"\nFine: "<<this->calculateFine(books[i].getNumberOfDaysUsed())<<std::endl;
            count++;
        }
        
    }
    if (count == 0){
        std::cout<<"No books available with the price less than 2500Rs."<<std::endl;
    }
}