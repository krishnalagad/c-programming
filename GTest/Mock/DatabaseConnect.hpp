#ifndef DATABASECONNECT_HPP
#define DATABASECONNECT_HPP

#include <string>

class DatabaseConnect {
    public:
        virtual bool login(std::string username, std::string password) { return true; }
        virtual bool logout(std::string username) {return true; }
        virtual int fetchRecord() { return -1; }
};

#endif // DATABASECONNECT_HPP
