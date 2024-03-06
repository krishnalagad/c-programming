#ifndef BUSINESSOWNER_HPP
#define BUSINESSOWNER_HPP

#include <iostream>
#include "BusinessType.hpp"

class BusinessOwner {
    private:
        const int _regId;
        std::string _name;
        BusinessType _type;
        int _age;
        int _taxableAmount;
        unsigned short _taxPercent;

    public:
        BusinessOwner() = delete;
        BusinessOwner(const BusinessOwner&) = default;
        BusinessOwner(BusinessOwner&&) = default;
        BusinessOwner& operator=(const BusinessOwner&) = default;
        BusinessOwner& operator=(BusinessOwner&&) = default;
        ~BusinessOwner() = default;

        BusinessOwner(int id, std::string name, BusinessType type, int age, int amount, unsigned short percent);

        int regId() const { return _regId; }

        std::string name() const { return _name; }
        void setName(const std::string &name) { _name = name; }

        BusinessType type() const { return _type; }
        void setType(const BusinessType &type) { _type = type; }

        int age() const { return _age; }
        void setAge(int age) { _age = age; }

        int taxableAmount() const { return _taxableAmount; }
        void setTaxableAmount(int taxableAmount) { _taxableAmount = taxableAmount; }

        unsigned short taxPercent() const { return _taxPercent; }
        void setTaxPercent(unsigned short taxPercent) { _taxPercent = taxPercent; }

        friend std::ostream &operator<<(std::ostream &os, const BusinessOwner &rhs);
};

#endif // BUSINESSOWNER_HPP
