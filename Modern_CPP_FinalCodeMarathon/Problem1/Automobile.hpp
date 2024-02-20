#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP

#include <iostream>

#include "Category.hpp"
#include "PrivilegeCategory.hpp"

class Automobile {
    private:
        const std::string _id;
        std::string _brand;
        Category _category;
        float _price;
        std::string _model;
        
    public:
        Automobile() = delete;
        Automobile(const Automobile&) = default;
        Automobile(Automobile&&) = default;
        Automobile& operator=(const Automobile&) = default;
        Automobile& operator=(Automobile&&) = default;
        ~Automobile() = default;

        // Custom parameterized constructor
        Automobile(std::string id, std::string brand, Category category, float price, std::string model);

        // getters and setters for member attributes
        std::string id() const { return _id; }

        std::string brand() const { return _brand; }
        void setBrand(const std::string &brand) { _brand = brand; }

        Category category() const { return _category; }
        void setCategory(const Category &category) { _category = category; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        std::string model() const { return _model; }
        void setModel(const std::string &model) { _model = model; }

        // output stream to print object data to console
        friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);

        // member functions
        PrivilegeCategory findPrivilegeType();
        float greenPassCost();
};

#endif // AUTOMOBILE_HPP
