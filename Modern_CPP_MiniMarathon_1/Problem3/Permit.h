#ifndef PERMIT_H
#define PERMIT_H

#include <string>
#include <ostream>
#include "PermitType.h"

class Permit {
    private:
        static int _counter;

        std::string _serial_number;
        PermitType _permit_type;
        int _permit_duration_left;

    public:
        // six special functions
        Permit() = delete;
        ~Permit() = default;
        Permit(const Permit&) = delete;
        Permit(Permit&&) = delete;
        Permit& operator=(const Permit&) = delete;
        Permit& operator=(Permit&&) = delete;

        // Custom parameterized constructor
        Permit(PermitType type, int durationLeft);

        std::string serialNumber() const { return _serial_number; }

        PermitType permitType() const { return _permit_type; }
        void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

        int permitDurationLeft() const { return _permit_duration_left; }
        void setPermitDurationLeft(int permit_duration_left) { _permit_duration_left = permit_duration_left; }

        friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

inline int Permit::_counter = 1000;

#endif // PERMIT_H
