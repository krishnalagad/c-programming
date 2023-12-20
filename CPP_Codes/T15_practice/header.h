#include <iostream>
#include <cstring>
#define Book_SIZE 100

class Book{
    private:
        int bookId;
        char bookName[50];
        int pageSize;
    public:
        Book();
        Book(char *, int);
        void displayAll();
        void acceptData(char *name, int size);
        void searchBook(int bookId);
        void modifyBook(int bookId);

        int getBookId() { return this->bookId; }
        void setBookId(int bookId) { this->bookId = bookId; }

        int getPageSize() { return pageSize; }
        void setPageSize(int pageSize_) { pageSize = pageSize_; }

        char* getBookName() { return bookName; }
        void setBookName(char *bookName_) { strcpy(this->bookName, bookName_); }
};