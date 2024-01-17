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

    bool operator<(const CityData& other) const {
        return name < other.name; 
    }
};

// custom hashing function, ie we pass object as akey to map
namespace std {
    template<>
    struct hash<CityData>{
       size_t operator()(const CityData& key) {
        return std::hash<std::string>()(key.name);
       }
    }; 
}

int main() {
    std::map<std::string, CityData> data;
    data["Pune"] = CityData("Pune", 500000, 29876.3, 92873.9);
    data["Mumbai"] = CityData("Mumbai", 500000, 29876.3, 92873.9);
    data["Banglore"] = CityData("Banglore", 500000, 29876.3, 92873.9);
    data["Chennai"] = CityData("Chennai", 500000, 29876.3, 92873.9);

    CityData& pune = data["Pune"];
    std::cout<<pune.population<<std::endl;

    std::map<CityData, uint32_t> foundedMap;
    foundedMap[CityData("Pune", 500000, 29876.3, 92873.9)] = 1178;  // object as a key.

    uint32_t foundedYear = foundedMap[CityData("Pune", 500000, 29876.3, 92873.9)];
    std::cout<<foundedYear<<std::endl;

    return 0;
}