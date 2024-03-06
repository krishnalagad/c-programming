#include "Automobile.hpp"

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "_id: " << rhs._id
       << " _brand: " << rhs._brand
       << " _category: " << static_cast<int> (rhs._category)
       << " _price: " << rhs._price
       << " _model: " << rhs._model;
    os << "\n";
    return os;
}

Automobile::Automobile(std::string id, std::string brand, Category category, float price, std::string model) 
    : _id(id), _brand(brand), _category(category), _price(price), _model(model)  {}

PrivilegeCategory Automobile::findPrivilegeType() {
    if ((this->_category == Category::PRIVATE) && (this->_price > 250000))
        return PrivilegeCategory::VIP;
    if (this->_category == Category::DEFENCE)
        return PrivilegeCategory::GOVT;
    
    return PrivilegeCategory::PERSONAL;
}

float Automobile::greenPassCost() {
    if ((this->_category == Category::PRIVATE) || (this->_category == Category::TRANSPORT))
        return 0.1 * this->_price;
    return 0.0f;
}
