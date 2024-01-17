#include <iostream>
#include <map>
#include <string>

struct CityData {
    std::string name;
    uint64_t population;
    double longitude;
    double latitude;

    CityData() : name(""), population(0), longitude(0.0), latitude(0.0) {}
    CityData(std::string name, uint64_t pop, double lon, double lat)
        : name(std::move(name)), population(pop), longitude(lon), latitude(lat) {}
};

int main() {
    std::map<std::string, CityData> data;
    data["Pune"] = CityData("Pune", 500000, 29876.3, 92873.9);
    data["Mumbai"] = CityData("Mumbai", 500000, 29876.3, 92873.9);
    data["Banglore"] = CityData("Banglore", 500000, 29876.3, 92873.9);
    data["Chennai"] = CityData("Chennai", 500000, 29876.3, 92873.9);

    CityData& pune = data["Pune"];
    std::cout<<pune.population<<std::endl;

    return 0;
}