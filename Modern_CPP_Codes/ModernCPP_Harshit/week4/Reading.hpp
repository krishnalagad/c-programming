#ifndef READING_HPP
#define READING_HPP

#include <iostream>
#include "ReadingType.hpp"

class Reading {
    private:
        ReadingType _readingType;
        float _readingValue;

    public:
        Reading() = delete;
        Reading(const Reading&) = delete;
        Reading(Reading&&) = default;
        Reading& operator=(const Reading&) = delete;
        Reading& operator=(Reading&&) = delete;
        ~Reading() = default;

        Reading(ReadingType type, float value);

        friend std::ostream &operator<<(std::ostream &os, const Reading &rhs);

        bool operator<(const Reading& rhs) {
            return _readingValue < rhs._readingValue;
        }
};

inline std::ostream &operator<<(std::ostream &os, const Reading &rhs) {
    os << "_readingType: " << static_cast<int> (rhs._readingType)
       << " _readingValue: " << rhs._readingValue;
    return os;
}

Reading::Reading(ReadingType type, float value): _readingType(type), _readingValue(value) {}

#endif // READING_HPP
