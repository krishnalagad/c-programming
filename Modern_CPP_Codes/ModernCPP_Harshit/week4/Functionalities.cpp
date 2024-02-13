#include "Functionalities.hpp"

void createObjects(Container &data) {
    data.push(Reading(ReadingType::TEMPERATURE, 32.12f));
    data.push(Reading(ReadingType::TEMPERATURE, 32.77f));
    data.push(Reading(ReadingType::TYRE_PRESSURE, 36.0f));
    data.push(Reading(ReadingType::RPM, 3000.0f));
}