#include <iostream>
#include "BankLoan.h"

std::ostream &operator<<(std::ostream &os, const BankLoan &rhs) {
    os << "_id: " << rhs._id
       << " _person_age: " << rhs._person_age
       << " _person_income: " << rhs._person_income
       << " _loan_intent: " << static_cast<int>(rhs._loan_intent)
       << " _loan_amount: " << rhs._loan_amount
       << " _int_rate: " << rhs._int_rate
       << " _status: " << static_cast<int> (rhs._status);
    os << "\n";
    return os;
}

BankLoan::BankLoan(int age, int income, LoanIntent intent, int amount, float intRate, LoanStatus status) 
    : _id(++_counter), _person_age(age), _person_income(income), _loan_intent(intent), _loan_amount(amount),
    _int_rate(intRate), _status(status) {}
