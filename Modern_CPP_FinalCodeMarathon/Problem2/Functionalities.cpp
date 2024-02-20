#include "Functionalities.hpp"

void createObjects(VehicleContainer &data, RecordsContainer &records) {
    records.emplace_back(
        ServiceRecord("SERV001", ServiceType::REGULAR, 2, 3400.0f, "Attendant 1", "Location 1"));
    records.emplace_back(
        ServiceRecord("SERV002", ServiceType::REPAIR, 2, 7200.0f, "Attendant 2", "Location 2"));
    records.emplace_back(
        ServiceRecord("SERV003", ServiceType::REPAIR, 2, 8400.0f, "Attendant 3", "Location 3"));

    data.emplace_back(
        "VEHICLE001", 36, records.at(0));
    data.emplace_back(
        "VEHICLE002", 45, records.at(1));
    data.emplace_back(
        "VEHICLE003", 12, records.at(2));
    data.emplace_back(
        "VEHICLE004", 80, records.at(1));
    data.emplace_back(
        "VEHICLE005", 92, records.at(0));
}

std::optional<std::list<Vehicle>> getLastInstancesOfVehicles(const VehicleContainer &data, int n) {
    if (data.empty())
        throw CustomMessageException("Data Container is empty!!");

    std::list<Vehicle> result;
    std::copy_if(data.crbegin(), data.crend(), std::back_inserter(result), [&](const Vehicle &v)
                 {
        if (n <= 0)
            return false;
        n--;
        return true; });

    if (result.empty())
        return std::nullopt;
    return result;
}

std::map<std::string, std::string> getKeyValPairOfIds(const VehicleContainer &data, const std::list<std::string> &idList){
    if (data.empty())
        throw CustomMessageException("Data Container is empty!!");

    std::map<std::string, std::string> result;
    for (const std::string &id : idList) {
        auto pos = std::find_if(std::begin(data), std::end(data), [&](const Vehicle &v)
                                { return v.vehicleId() == id; });

        if (pos != std::end(data)) {
            result.emplace(
                pos->vehicleId(), pos->latestServiceRecord().get().serviceId());
        } else {
            throw RecordNotFoundException("Record with given ID is not exists in container!!");
        }
    }

    return result;
}

std::map<std::string, ServiceRecord> getKeyValOfIdAndService(const VehicleContainer &data) {
    if (data.empty())
        throw CustomMessageException("Data Container is empty!!");
    
    auto itr = std::max_element(data.begin(), data.end(), [](const Vehicle& v1, const Vehicle& v2){
        return v1.latestServiceRecord().get().charges() < v2.latestServiceRecord().get().charges();
    });

    std::map<std::string, ServiceRecord> result;
    result.emplace(itr->vehicleId(), itr->latestServiceRecord().get());

    return result;
}

float getAverageCharges(const VehicleContainer &data) {
    if (data.empty())
        throw CustomMessageException("Data Container is empty!!");

    float total = 0.0f;
    int count = 0;
    auto totVal = std::accumulate(data.begin(), data.end(), 0.0f, [&](float tot, const Vehicle& v){
        if (v.latestServiceRecord().get().type() == ServiceType::REGULAR) {
            count += 1;
            return tot + v.latestServiceRecord().get().charges();
        } else {
            return 0.0f;
        }
    });

    if (count == 0)
        throw RecordNotFoundException("No such a record found!!");
    return totVal / count;
}

std::string getVehicleIdByServiceId(const VehicleContainer &data, std::string serviceId) {
    if (data.empty())
        throw CustomMessageException("Data Container is empty!!");\
    
    auto pos = std::find_if(std::begin(data), std::end(data), [&](const Vehicle& v) {
        return v.latestServiceRecord().get().serviceId() == serviceId;
    });
    if (pos != std::end(data)) {
        return pos->vehicleId();
    }

    throw RecordNotFoundException("Record with given ID doesn't exists!!");
}
