#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <vector>
#include <ostream>
#include "Unit.hpp"

using UnitContainer = std::vector<Unit>;

class Account {
    private:
        int _accountNumber;
        UnitContainer _accountUnits;
        
    public:
        Account() = default;
        Account(const Account&) = default;
        Account(Account&&) = default;
        Account& operator=(const Account&) = default;
        Account& operator=(Account&&) = default;
        ~Account() = default;

        Account(int number, const UnitContainer& units);

        int accountNumber() const { return _accountNumber; }

        UnitContainer accountUnits() const { return _accountUnits; }

        friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_HPP
