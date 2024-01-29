#include "Functionalities.h"

void createObjects(Container& data) {
    Engine supraEngine = Engine(EngineType::HYBRID, 900, 660);
    Engine mustangEngine = Engine(EngineType::HYBRID, 850, 630);
    Engine gtrEngine = Engine(EngineType::HYBRID, 1020, 720);
    data.push_back(
        std::make_shared<Car>(
            "Toyota Supra",
            CarType::SPORTS,
            supraEngine,
            80000.0f
        )
    );
    data.push_back(
        std::make_shared<Car>(
            "Ford Mustang",
            CarType::SPORTS,
            mustangEngine,
            80000.0f
        )
    );
    data.push_back(
        std::make_shared<Car>(
            "Nissan GTR",
            CarType::SPORTS,
            gtrEngine,
            80000.0f
        )
    );
}