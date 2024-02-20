#include "Account.hpp"

std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "_accountNumber: " << rhs._accountNumber;
    os << "n_accountUnits: \n";
    for(const Unit& unit: rhs.accountUnits()) {
        os << unit;
    }
    os << "\n";
    return os;
}

Account::Account(int number, const UnitContainer &units)
    : _accountNumber(number), _accountUnits(units) {}
