#include <string>
#include <iostream>
#include "Engine.h"

Engine::Engine(EngineType engineType, int engineHorsepower, int engineTorque)
    : _engineNumber("ENGINE2024-" + std::to_string(++_counter)), _engineType(engineType), _engineHorsepower(engineHorsepower),
    _engineTorque(engineTorque) {}