#ifndef BANKLOAN_H
#define BANKLOAN_H

#include <iostream>
#include "LoanIntent.h"
#include "LoanStatus.h"

class BankLoan {
private:
    static int _counter;
    const int _id;  // is must be const

    int _person_age;
    int _person_income;
    LoanIntent _loan_intent;
    int _loan_amount;
    float _int_rate;
    LoanStatus _status;

public:
    // six special functions
    BankLoan() = delete;
    BankLoan(const BankLoan&) = delete;
    BankLoan(BankLoan&&) = delete;
    BankLoan& operator=(const BankLoan&) = delete;
    BankLoan& operator=(BankLoan&&) = delete;
    ~BankLoan() = default;

    // custom parameterized constructor
    BankLoan(int age, int income, LoanIntent intent, int amount, float intRate, LoanStatus status);

    int id() const { return _id; }

    int personAge() const { return _person_age; }
    void setPersonAge(int person_age) { _person_age = person_age; }

    int personIncome() const { return _person_income; }
    void setPersonIncome(int person_income) { _person_income = person_income; }

    LoanIntent loanIntent() const { return _loan_intent; }
    void setLoanIntent(const LoanIntent &loan_intent) { _loan_intent = loan_intent; }

    int loanAmount() const { return _loan_amount; }
    void setLoanAmount(int loan_amount) { _loan_amount = loan_amount; }

    float intRate() const { return _int_rate; }
    void setIntRate(float int_rate) { _int_rate = int_rate; }

    LoanStatus status() const { return _status; }
    void setStatus(const LoanStatus &status) { _status = status; }

    friend std::ostream &operator<<(std::ostream &os, const BankLoan &rhs);
};

inline int BankLoan::_counter = 0;

#endif // BANKLOAN_H
