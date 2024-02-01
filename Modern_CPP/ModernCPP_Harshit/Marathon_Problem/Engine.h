#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <iostream>
#include "EngineType.h"

class Engine {
    private:
        // static int _counter;
        std::string _engineNumber {"XXXXXX"};
        EngineType _engineType {EngineType::ICT};
        int _engineHorsepower {600};
        int _engineTorque {800};

    public:
        Engine() = default;
        Engine(const Engine&) = default;
        Engine(Engine&&) = default;
        Engine& operator=(const Engine&) = delete;
        Engine& operator=(Engine&&) = default;
        ~Engine() { std::cout << "Engine destroyed!! " << _engineNumber << std::endl; };
        // ~Engine() {};

        // Engine(EngineType, int, int);
        Engine(std::string engineNumber, EngineType engineType, int engineHp, int engineTorque);

        std::string engineNumber() const { return _engineNumber; }
        void setEngineNumber(const std::string &engineNumber) { _engineNumber = engineNumber; }

        EngineType engineType() const { return _engineType; }
        void setEngineType(const EngineType &engineType) { _engineType = engineType; }

        int engineHorsepower() const { return _engineHorsepower; }
        void setEngineHorsepower(int engineHorsepower) { _engineHorsepower = engineHorsepower; }

        int engineTorque() const { return _engineTorque; }
        void setEngineTorque(int engineTorque) { _engineTorque = engineTorque; }

        friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);
};

// inline int Engine::_counter = 100;

#endif // ENGINE_H
