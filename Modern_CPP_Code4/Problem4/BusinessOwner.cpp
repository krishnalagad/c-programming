#include "BusinessOwner.hpp"

BusinessOwner::BusinessOwner(int id, std::string name, BusinessType type, int age, int amount, unsigned short percent)
: _regId(id), _name(name), _type(type), _age(age), _taxableAmount(amount), _taxPercent(percent){}


std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs) {
    os << "_regId: " << rhs._regId
       << " _name: " << rhs._name
       << " _type: " << static_cast<int> (rhs._type)
       << " _age: " << rhs._age
       << " _taxableAmount: " << rhs._taxableAmount
       << " _taxPercent: " << rhs._taxPercent;
    os << "\n";
    return os;
}
