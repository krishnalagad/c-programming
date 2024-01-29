#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <iostream>
#include "EngineType.h"

class Engine {
    private:
        static int _counter;
        std::string _engineNumber {"XXXXXX"};
        EngineType _engineType {EngineType::ICT};
        int _engineHorsepower {600};
        int _engineTorque {800};

    public:
        Engine() = default;
        // ~Engine() { std::cout << "Engine destroyed!! " << _engineNumber << std::endl; };
        ~Engine() {};

        Engine(EngineType, int, int);

        std::string engineNumber() const { return _engineNumber; }
        void setEngineNumber(const std::string &engineNumber) { _engineNumber = engineNumber; }

        EngineType engineType() const { return _engineType; }
        void setEngineType(const EngineType &engineType) { _engineType = engineType; }

        int engineHorsepower() const { return _engineHorsepower; }
        void setEngineHorsepower(int engineHorsepower) { _engineHorsepower = engineHorsepower; }

        int engineTorque() const { return _engineTorque; }
        void setEngineTorque(int engineTorque) { _engineTorque = engineTorque; }
};

inline int Engine::_counter = 100;

#endif // ENGINE_H
