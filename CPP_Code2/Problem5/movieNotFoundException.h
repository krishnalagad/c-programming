#ifndef MOVIENOTFOUNDEXCEPTION_H
#define MOVIENOTFOUNDEXCEPTION_H

#include <iostream>

class MovieNotFoundException: public std::exception
{
private:
    std::string message;
public:
    MovieNotFoundException();
    ~MovieNotFoundException();
    std::string what() {
        return message;
    }
};

MovieNotFoundException::MovieNotFoundException(): message("Movie Not Available!!")
{
}

MovieNotFoundException::~MovieNotFoundException()
{
}


#endif // MOVIENOTFOUNDEXCEPTION_H
