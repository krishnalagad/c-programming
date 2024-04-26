#ifndef MYDATABASE_HPP
#define MYDATABASE_HPP

#include <iostream>
#include <functional>
#include "DatabaseConnect.hpp"

using DatabaseRef = std::reference_wrapper<DatabaseConnect>;
class MyDatabase {
    DatabaseRef dbC;
    public:
        MyDatabase() = delete;
        MyDatabase(DatabaseRef _dbC);
        int Init(std::string username, std::string password) {
            if (dbC.get().login(username, password) !=true) {
                if (dbC.get().login(username, password) != true) {
                    std::cout << "DB FAILURE 2nd TIME!!" << std::endl; return -1;
                } else {
                    std::cout << "DB SUCCESS ON 2nd ATTEMPT!!" << std::endl; return 1;
                } 
            } else {
                std::cout << "DB SUCCESS!!" << std::endl; return 1;
            }
        }
        ~MyDatabase() = default;
};

#endif // MYDATABASE_HPP
