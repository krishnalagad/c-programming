#include "Functionalities.hpp"

void createObjects(AccountPointerMap &data) {
    data.emplace(
        std::make_pair<int, AccountPointer>(
            1004,
            std::make_shared<Account>(
                1004,
                UnitContainer{
                    {"UNIT01", "DRIVER 1", UnitType::MINI, 45000},
                    {"UNIT02", "DRIVER 2", UnitType::PREMIUM, 65000},
                    {"UNIT03", "DRIVER 3", UnitType::PRIME, 55000},
                    {"UNIT04", "DRIVER 4", UnitType::MINI, 45000},
                    {"UNIT05", "DRIVER 5", UnitType::PREMIUM, 65000},
                    {"UNIT06", "DRIVER 6", UnitType::PRIME, 55000}})));
    data.emplace(
        std::make_pair<int, AccountPointer>(
            1005,
            std::make_shared<Account>(
                1005,
                UnitContainer{
                    {"UNIT01", "DRIVER 1", UnitType::MINI, 34200},
                    {"UNIT02", "DRIVER 2", UnitType::PREMIUM, 123100},
                    {"UNIT03", "DRIVER 3", UnitType::PRIME, 78999}})));
    data.emplace(
        std::make_pair<int, AccountPointer>(
            1006,
            std::make_shared<Account>(
                1006,
                UnitContainer{
                    {"UNIT01", "DRIVER 1", UnitType::MINI, 9385},
                    {"UNIT02", "DRIVER 2", UnitType::PREMIUM, 29837},
                    {"UNIT03", "DRIVER 3", UnitType::PRIME, 930875},
                    {"UNIT04", "DRIVER 4", UnitType::PREMIUM, 123100},
                    {"UNIT05", "DRIVER 5", UnitType::PRIME, 78999}})));
    data.emplace(
        std::make_pair<int, AccountPointer>(
            1007,
            std::make_shared<Account>(
                1007,
                UnitContainer{
                    {"UNIT01", "DRIVER 1", UnitType::MINI, 45100},
                    {"UNIT02", "DRIVER 2", UnitType::PREMIUM, 65900},
                    {"UNIT03", "DRIVER 3", UnitType::PRIME, 55090}})));
    data.emplace(
        std::make_pair<int, AccountPointer>(
            1008,
            std::make_shared<Account>(
                1008,
                UnitContainer{
                    {"UNIT01", "DRIVER 1", UnitType::MINI, 45400},
                    {"UNIT02", "DRIVER 2", UnitType::PREMIUM, 69500},
                    {"UNIT03", "DRIVER 3", UnitType::PRIME, 57500}})));
    
}

bool addfareAmount(const AccountPointerMap &data, int accountNumber, std::string unitNumber, int amount) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");
    
    auto pos = std::find_if(std::begin(data), std::end(data), [&](std::pair<int, AccountPointer>&& p) {
        return p.first == accountNumber;
    });
    
    if (pos != std::end(data)) {
        UnitContainer units = pos->second.get()->accountUnits();
        auto pos = std::find_if(std::begin(units), std::end(units), [&](const Unit& unit) {
            return unit.unitRegNumber() == unitNumber;
        });
        if (pos != std::end(units)) {
            pos->setUnitMonthlyRevenue(amount);
            return true;
        } else {
            throw RecordNotFoundException("Account exists with given ID but Unit doens't exists with given ID!!");
        }
    } else {
        throw RecordNotFoundException("Account with given ID is not exists!!");
    }
    return false;
}

int getTotalRevenueForAccount(const AccountPointerMap &data, int accountNumber) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");
    
    auto pos = std::find_if(std::begin(data), std::end(data), [&](std::pair<int, AccountPointer>&& p) {
        return p.first == accountNumber;
    });
    if (pos != std::end(data)) {
        UnitContainer units = pos->second.get()->accountUnits();
        if (!units.empty()) {
            int answer = std::accumulate(units.begin(), units.end(), 0, [](int total, const Unit& unit){
                return total + unit.unitMonthlyRevenue();
            });
            return answer;
            
        } else    
            throw CustomMessageException("Account has found, but no units exists for this account!!");
    } else {
        throw RecordNotFoundException("Account with given ID is not exists!!");
    }
    throw CustomMessageException("Bad Operation!!");
}

int getBonusAmountForAccount(const AccountPointerMap &data, int accountNumber) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");
    
    auto pos = std::find_if(std::begin(data), std::end(data), [&](std::pair<int, AccountPointer>&& p) {
        return p.first == accountNumber;
    });

    if (pos != std::end(data)) {
        UnitContainer units = pos->second.get()->accountUnits();
        if (!units.empty()) {
            int answer = std::accumulate(units.begin(), units.end(), 0, [](int total, const Unit& unit){
                return total + unit.unitMonthlyRevenue();
            });
            if (answer <= 50000)
                return 1000;
            else if (answer > 50000)
                return 2000;
        } else    
            throw CustomMessageException("Account has found, but no units exists for this account!!");
    } else {
        throw RecordNotFoundException("Account with given ID is not exists!!");
    }
    return -1;
}