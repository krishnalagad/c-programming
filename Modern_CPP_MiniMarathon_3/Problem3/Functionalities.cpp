#include "Functionalities.hpp"

void createObjects(CarVariantContainer &data) {
    data.push_back(
        std::make_shared<EvCar>(
            101, ChassisType::LADDER, 33.0f));
    data.push_back(
        std::make_shared<ICECar>(
            102, FuelType::DIESEL, 19.0f));
    data.push_back(
        std::make_shared<EvCar>(
            103, ChassisType::TABULAR, 45.0f));
    data.push_back(
        std::make_shared<ICECar>(
            104, FuelType::PETROL, 21.0f));
    data.push_back(
        std::make_shared<EvCar>(
            105, ChassisType::LADDER, 21.0f));
    data.push_back(
        std::make_shared<ICECar>(
            105, FuelType::DIESEL, 32.0f));
}



// bool isFuelTankCapacityAbove30(const CarVariantContainer &data){
//     if (data.empty()) 
//         throw CustomMessageException("Container is empty!!");
    
//     bool flag = true;
//     for (const CarVariant& v: data) {
//         if (std::holds_alternative<ICECarPointer>(v)) {
//             auto ptr = std::get<ICECarPointer>(v);
//             if (ptr->fuelTankCapacity() >= 30) 
//                 flag = true;
//             else 
//                 return false;
//         }
//     }
//     return flag;
// }

// Implementatio of method using std algorithm: std::any_of()
bool isFuelTankCapacityAbove30(const CarVariantContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");
    
    return std::any_of(data.begin(), data.end(), [](const CarVariant& v) {
        if (std::holds_alternative<ICECarPointer>(v)) {
            auto ptr = std::get<ICECarPointer>(v);
            return ptr->fuelTankCapacity() >= 30;
        }
        return false;
    });
}

// std::optional<CarVariantContainer> getFirstNCarsBasedOnType(const CarVariantContainer& data, CarType type, int n) {
//     if (data.empty()) 
//         throw CustomMessageException("Container is empty!!");

//     int val = static_cast<int>(type);
//     CarVariantContainer res;
//     for (const CarVariant& v: data) {
//         if(val == 1) {
//             if (std::holds_alternative<ICECarPointer>(v)) {
//                 res.push_back(std::get<ICECarPointer>(v));
//             } 
//         } else if (val == 2) {
//             if (std::holds_alternative<EvCarPointer>(v)) {
//                 res.push_back(std::get<EvCarPointer>(v));
//             }
//         }
//     }

//     if (res.empty()) 
//         return std::nullopt;
//     return res;
// }

// Implementation of method using std algorithm: std::copy_if()
std::optional<CarVariantContainer> getFirstNCarsBasedOnType(const CarVariantContainer &data, CarType type, int n) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");

    int val = static_cast<int>(type);
    CarVariantContainer res;
    std::copy_if(data.begin(), data.end(), std::back_inserter(res), [&val](const CarVariant& v) {
        if (val == 1) 
            return std::holds_alternative<EvCarPointer>(v);
        
        return std::holds_alternative<ICECarPointer>(v);
    });

    if (res.empty()) 
        return std::nullopt;
    return res;
}

// void printCountOfEvCarInstances(const CarVariantContainer &data) {
//     if (data.empty()) 
//         throw CustomMessageException("Container is empty!!");

//     int count = 0;
//     for (const CarVariant& v: data) {
//         if (std::holds_alternative<EvCarPointer>(v)) 
//             count += 1;
//     }

//     std::cout << "The count of EvCar in the container is: " << count << std::endl;
// }

// Implementation of method using std algorithm: std::count_if()
void printCountOfEvCarInstances(const CarVariantContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");

    int count = std::count_if(data.begin(), data.end(), [](const CarVariant& v) {
        return std::holds_alternative<EvCarPointer>(v);
    });

    std::cout << "The count of EvCar in the container is: " << count << std::endl;
}

// std::string getChassisTypeById(const CarVariantContainer &data, int id) {
//     if (data.empty()) 
//         throw CustomMessageException("Container is empty!!");
    
//     int chassisType = 0;;
//     for (const CarVariant& v: data) {
//         if (std::holds_alternative<EvCarPointer>(v)) {
//             EvCarPointer e = std::get<EvCarPointer>(v);
//             if (e->id() == id) {
//                 chassisType = static_cast<int>(e->chassisType());
//             }
//         }
//     }
    
//     if(chassisType)
//         return "LADDER";
//     else 
//         return "TABULAR";
// }

// Implementation of function using std algorithm: std::find_if()
std::string getChassisTypeById(const CarVariantContainer &data, int id) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");
    
    auto it = std::find_if(data.begin(), data.end(), [&id](const CarVariant& v) {
        if (std::holds_alternative<EvCarPointer>(v)) {
            EvCarPointer e = std::get<EvCarPointer>(v);
            return e->id() == id;
        }
        return false;
    });
    
    if (it != data.end()) {
        EvCarPointer e = std::get<EvCarPointer>(*it);
        return (e->chassisType() == ChassisType::LADDER) ? "LADDER" : "TABULAR";
    }
    
    throw RecordNotFoundException("ID not found!!"); 
}

// float getTotalBatteryCapacityOfEvCars(const CarVariantContainer &data){
//     if (data.empty()) 
//         throw CustomMessageException("Container is empty!!");
    
//     float total = 0.0f;
//     for (const CarVariant& v: data) {
//         if (std::holds_alternative<EvCarPointer>(v)) {
//             EvCarPointer e = std::get<EvCarPointer>(v);
//             total += e->batteryCapacity();
//         }
//     }
//     return total;
// }

// Implementation of function using std algorithm: std::accumulate()
float getTotalBatteryCapacityOfEvCars(const CarVariantContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");
    
    return std::accumulate(data.begin(), data.end(), 0.0f, [](float total, const CarVariant& v) {
        if (std::holds_alternative<EvCarPointer>(v)) {
            EvCarPointer e = std::get<EvCarPointer>(v);
            return total + e->batteryCapacity();
        }
        return total;
    });
}

void printDataOfCarObject(const CarVariantContainer &data, int n) {
    if (data.empty()) 
        throw CustomMessageException("Container is empty!!");
    if (n > data.size())
        throw RecordNotFoundException("Container index is out of bounds!!");

    if (std::holds_alternative<EvCarPointer>(data.at(n))) {
        EvCarPointer ptr = std::get<EvCarPointer>(data.at(n));
        std::cout << *ptr;
    }
    if (std::holds_alternative<ICECarPointer>(data.at(n))) {
        ICECarPointer ptr = std::get<ICECarPointer>(data.at(n));
        std::cout << *ptr;
    }
}

std::optional<CarVariantContainer> removeFewObjectsAndGetContainer(const CarVariantContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");
    
    CarVariantContainer result;
    std::copy(data.begin(), data.end(), result.begin());
    if (result.empty())
        throw RecordNotFoundException("Result container is empty, Copy failed!!");

    auto newEnd = std::remove_if(result.begin(), result.end(), [](const CarVariant& v){
        return std::holds_alternative<ICECarPointer>(v);
    });

    result.resize(std::distance(result.begin(), newEnd));
    if (result.empty())
        return std::nullopt;
    return result;
}
