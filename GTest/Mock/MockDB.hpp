#ifndef MOCKDB_HPP
#define MOCKDB_HPP

#include "DatabaseConnect.hpp"
#include <gmock/gmock.h>

class MockDB: public DatabaseConnect {
    public:
        MOCK_METHOD0(fetchRecord, int());
        MOCK_METHOD1(logout, bool(std::string username));
        MOCK_METHOD2(login, bool(std::string username, std::string password));

};

#endif // MOCKDB_HPP
