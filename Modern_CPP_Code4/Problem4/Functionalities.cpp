#include "Functionalities.hpp"

void createObjects(VariantContainer &data) {
    data.push_back(
        std::make_shared<Employee>(
            100001, "Employee 1", EmployeeType::FULL_TIME, 24, 2300, 6));
    data.push_back(
        std::make_shared<Employee>(
            100002, "Employee 2", EmployeeType::PERMIT_HOLDER, 22, 1200, 5));
    data.push_back(
        std::make_shared<BusinessOwner>(
            100003, "BusinessOwner 1", BusinessType::MULTISTATE, 24, 23000, 12));
    data.push_back(
        std::make_shared<BusinessOwner>(
            100004, "BusinessOwner 2", BusinessType::INTERNATIONAL, 36, 45000, 24));
    data.push_back(
        std::make_shared<BusinessOwner>(
            100005, "BusinessOwner 3", BusinessType::SME, 28, 12000, 16));        
}

int getCountOfBusinessInstances(const VariantContainer &data, int age) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");

    // std::cout_if() algorithm to get count based in given condition
    auto count = std::count_if(data.begin(), data.end(), [&](const Variant& v){
        if (std::holds_alternative<BusinessPointer>(v)) {
            return std::get<BusinessPointer>(v).get()->age() > age;
        }
        return false;
    });


    return count;
}

bool isEmployeeTaxableAmountAboveThreshold(const VariantContainer &data, int th) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");

    // std::all_of() algorithm to get true only if all objects passes the criteria
    bool flag = std::all_of(data.begin(), data.end(), [&](const Variant& v){
        if (std::holds_alternative<EmployeePointer>(v)) {
            return std::get<EmployeePointer>(v).get()->taxableAmount() > th;
        }
        return false;
    });

    return flag;
}

VariantContainer getInstancesWithTaxPercentBelowThreshold(const VariantContainer &data, std::promise<int> &p) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");
    
    int th = p.get_future().get();
    VariantContainer result;
    std::copy_if(data.begin(), data.end(), std::back_inserter(result), [&](const Variant& v){
        if (std::holds_alternative<EmployeePointer>(v)) {
            return std::get<EmployeePointer>(v)->taxPercent() < th;
        }
        if (std::holds_alternative<BusinessPointer>(v)) {
            return std::get<BusinessPointer>(v)->taxPercent() < th;
        }
        return false;
    });

    if (result.empty())
        throw RecordNotFoundException("Records not found with given specifications!!");

    return result;
}
