#include "Functionalities.h"
#include "CustomSensorWithMessageException.h"
#include <iostream>

int main() {
    SensorPointerListContainer data;
    creteObjects(data);
    try {
        std::string result = isSensorsAbove25ReadingExists(data, 25) ? "Yes" : "No";
        std::cout << "Does sensor Exists whose reading value greater than 25: " << result <<std::endl;
        float avgReading = getAverageReadingValueOfSensors(data, SensorType::TEMPERATURE);
        std::cout << "Average of Sensor reading whose type is TEMPERATURE: " << avgReading << std::endl;
    } catch(CustomSensorWithMessageException& e) {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    SensorPointerListContainer resultContainer;
    try {
        resultContainer = getSensorsWithReadingAbove15AndTypeTyre(data);
        for (const SensorPointer& ptr: resultContainer) 
            std::cout << *ptr;
    } catch(CustomSensorWithMessageException e) {
        std::cerr << e.what() << '\n';
    }
    
    
    
    return 0;
}