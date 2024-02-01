#include <string>
#include <iostream>
#include "Engine.h"

// Engine::Engine(EngineType engineType, int engineHorsepower, int engineTorque)
//     : _engineNumber("ENGINE2024-" + std::to_string(++_counter)), _engineType(engineType), _engineHorsepower(engineHorsepower),
//     _engineTorque(engineTorque) {}

std::ostream &operator<<(std::ostream &os, const Engine &rhs) {
    os << "_engineNumber: " << rhs._engineNumber
       << " _engineType: " << static_cast<int>(rhs._engineType)
       << " _engineHorsepower: " << rhs._engineHorsepower
       << " _engineTorque: " << rhs._engineTorque;
    return os;
}

Engine::Engine(std::string engineNumber, EngineType engineType, int engineHp, int engineTorque)
    : _engineNumber(engineNumber), _engineType(engineType), _engineHorsepower(engineHp),
    _engineTorque(engineTorque) {}
