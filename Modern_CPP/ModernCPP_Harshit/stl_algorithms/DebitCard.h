#ifndef DEBITCARD_H
#define DEBITCARD_H

#include <string>
#include "DebitCardType.h"
#include <iostream>

class DebitCard {
    private:
        const unsigned short _cvv;
        const long _cardNumber;
        std::string _expiryDate;
        const DebitCardType _cardType;
        
    public:
        DebitCard() = delete;
        DebitCard(unsigned short cvv, long cardNumber, std::string expiryDate, DebitCardType cardType);
        DebitCard(const DebitCard&) = delete;
        DebitCard& operator=(const DebitCard&) = delete;
        DebitCard(DebitCard&&) = delete;
        DebitCard& operator=(DebitCard&&) = delete;
        ~DebitCard() { std::cout<<"Debit card destroyed!! "<<_cardNumber<<std::endl; };

        unsigned short cvv() const { return _cvv; }
        long cardNumber() const { return _cardNumber; }
        const std::string& expiryDate() const { return _expiryDate; }     // return type is rvalue ref and acctually returning lvalue, so use one & only
        DebitCardType cardType() const { return _cardType; }

        friend std::ostream &operator<<(std::ostream &os, const DebitCard &rhs);
};

#endif // DEBITCARD_H
