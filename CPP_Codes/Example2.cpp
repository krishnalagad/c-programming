#include <iostream>
#include <cstring>
using namespace std;

class Book {
    private:
        char title[];
        char author[];
        int pageCount;
    public:
        Book() {
            strcpy(title, "AAAA");
            strcpy(author, "MEME")
            pageCount = 120
        }
    
        void display() {
            cout<<title;
        }

};

int main()
{
    Book b1;
    b1.display();
    return 0;
}
