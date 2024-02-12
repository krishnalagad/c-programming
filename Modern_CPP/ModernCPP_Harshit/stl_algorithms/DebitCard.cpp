#include "DebitCard.h"
#include <iostream>

DebitCard::DebitCard(unsigned short cvv, long cardNumber, std::string expiryDate, DebitCardType cardType)
    : _cvv(cvv), _cardNumber(cardNumber), _expiryDate(std::move(expiryDate)), _cardType(cardType) {
}

std::ostream &operator<<(std::ostream &os, const DebitCard &rhs) {
    os << "_cvv: " << rhs._cvv
       << " _cardNumber: " << rhs._cardNumber
       << " _expiryDate: " << rhs._expiryDate
       << " _cardType: " << static_cast<int> (rhs._cardType);
    return os;
}

