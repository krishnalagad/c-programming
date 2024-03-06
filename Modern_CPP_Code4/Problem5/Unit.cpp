#include "Unit.hpp"
std::ostream &operator<<(std::ostream &os, const Unit &rhs) {
    os << "_unitRegNumber: " << rhs._unitRegNumber
       << " _unitDriverName: " << rhs._unitDriverName
       << " _unitType: " << static_cast<int> (rhs._unitType)
       << " _unitMonthlyRevenue: " << rhs._unitMonthlyRevenue;
    os << "\n";
    return os;
}

Unit::Unit(std::string reg, std::string name, UnitType type, int revenue)
    : _unitRegNumber(reg), _unitDriverName(name), _unitType(type), _unitMonthlyRevenue(revenue) {}
