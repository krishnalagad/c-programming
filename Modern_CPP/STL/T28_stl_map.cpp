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

    CityData& delhi = data["Delhi"];    // if the key is not present in map, then new record with tha key will create.
    delhi.population = 1200000;
    delhi.name = "Delhi";
    delhi.longitude = 2398.5;
    delhi.latitude = 12356.67;
    std::cout<<delhi.population<<std::endl;

    const auto& cities = data;
    auto it = cities.find("Delhi");
    if (it != cities.end()) {
        const CityData& city = cities.at("Delhi");
        std::cout<<city.name<<std::endl;
    }

    return 0;
}