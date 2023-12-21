#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstring>
#define BOOK_SIZE 3

class Book
{
    private:
        int bookId;
        char bookName[50];
        char authorName[50];
        int price;
        int numberOfDaysUsed;
    public:
        Book();
        Book(char *, char *, int, int);
        void display();
        int calculateFine(int days);
        void accept(char *bookName, char *authorName, int price, int days);
        void displayNamesStartWithA(char ch);
        void displayBooksLowerThan2500();

        int getBookId() { return bookId; }
        void setBookId(int bookId_) { bookId = bookId_; }

        char * getBookName()  { return bookName; }
        void setBookName(char *bookName_) { strcpy(this->bookName, bookName_); }

        char * getAuthorName()  { return authorName; }
        void setAuthorName(char *authorName_) { strcpy(this->authorName, authorName_); }

        int getPrice()  { return price; }
        void setPrice(int price_) { price = price_; }

        int getNumberOfDaysUsed()  { return numberOfDaysUsed; }
        void setNumberOfDaysUsed(int numberOfDaysUsed_) { numberOfDaysUsed = numberOfDaysUsed_; }
    };
#endif // BOOK_H
