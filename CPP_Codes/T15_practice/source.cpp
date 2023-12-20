#include <iostream>
#include <cstring>
#include "header.h"

static int idCounter = 100;
Book books[Book_SIZE];
static int count = 0;

Book::Book(){
    this->bookId = idCounter;
    idCounter++;
    this->pageSize = 200;
    strcpy(this->bookName, "Default");
}
Book::Book(char *name, int pageSize){
    this->bookId = idCounter;
    idCounter++;
    this->pageSize = pageSize;
    strcpy(this->bookName, name);
}

void Book::displayAll() {
    for (int i = 0; i < count; i++){
        std::cout<<"\n\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nPage numbers: "<<books[i].getPageSize()<<std::endl;
    } 
}

void Book::acceptData(char *name, int size){
    if (count < Book_SIZE){
        static int idGen = 100;
        books[count].setBookId(idGen);
        books[count].setBookName(name);
        books[count].setPageSize(size);
        count += 1;
        idGen++;
    } else {
        std::cout<<"\nLibrary quota is full!!"<<std::endl;
    }
}

void Book::searchBook(int bookId){
    bool flag = true;
    for (int i = 0; i < count; i++){
        if (bookId == books[i].getBookId()){
            std::cout<<"\nBook found!!\n";
            std::cout<<"\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nPage numbers: "<<books[i].getPageSize()<<std::endl;            
            break;
        } else {
            flag = false;
        }
    } 
    if (!flag){
        std::cout<<"\nBook not found!!\n";
    }
    
}

void Book::modifyBook(int bookId){
    bool flag = true;
    for (int i = 0; i < count; i++){
        if (bookId == books[i].getBookId()){
            std::cout<<"\nBook found!! Original details\n";
            std::cout<<"\nBook Id: "<<books[i].getBookId()<<"\nBook Name: "<<books[i].getBookName()<<"\nPage numbers: "<<books[i].getPageSize()<<std::endl;  
            
            std::cout<<"\nEnter new name of book: "; 
            char name[50];
            std::cin>>name;
            books[i].setBookName(name); 

            std::cout<<"\nEnter new page size of book: "; 
            int no;
            std::cin>>no;
            books[i].setPageSize(no);    
            break;
        } else {
            flag = false;
        }
    } 
    if (!flag){
        std::cout<<"\nBook you want eddit is not found!!\n";
    }
}

