#ifndef UNIT_HPP
#define UNIT_HPP

#include "UnitType.hpp"
#include <iostream>

class Unit {
    private:
        std::string _unitRegNumber;
        std::string _unitDriverName;
        UnitType _unitType;
        int _unitMonthlyRevenue;
        
    public:
        Unit() = default;
        Unit(const Unit&) = default;
        Unit(Unit&&) = default;
        Unit& operator=(const Unit&) = default;
        Unit& operator=(Unit&&) = default;
        ~Unit() = default;

        // Custom parameterized constructor
        Unit(std::string reg, std::string name, UnitType type, int revenue);

        // getters and setters
        std::string unitRegNumber() const { return _unitRegNumber; }
        std::string unitDriverName() const { return _unitDriverName; }
        UnitType unitType() const { return _unitType; }
        int unitMonthlyRevenue() const { return _unitMonthlyRevenue; }
        void setUnitMonthlyRevenue(int unitMonthlyRevenue) { _unitMonthlyRevenue = unitMonthlyRevenue; }

        friend std::ostream &operator<<(std::ostream &os, const Unit &rhs);
        
};

#endif // UNIT_HPP
