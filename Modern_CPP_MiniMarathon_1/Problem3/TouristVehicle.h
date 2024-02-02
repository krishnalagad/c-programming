#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include <string>
#include <memory>
#include <ostream>
#include "TouristVehicleType.h"
#include "Permit.h"

using PermitPointer = std::shared_ptr<Permit>;

class TouristVehicle {
    private:
        static int _counter;

        std::string _number {"MH12CM2345"};
        TouristVehicleType _type {TouristVehicleType::BUS};
        int _seat_count {24};
        float _per_hour_booking_charge {30.0f};
        PermitPointer _permit;
        
    public:
        TouristVehicle() = default;
        ~TouristVehicle() = default;
        TouristVehicle(const TouristVehicle&) = default;
        TouristVehicle(TouristVehicle&&) = delete;
        TouristVehicle& operator=(const TouristVehicle&) = default;
        TouristVehicle& operator=(TouristVehicle&&) = delete;

        // custom parameterized constructor
        TouristVehicle(TouristVehicleType type, int seatCount, float perHourCharges, PermitPointer permit);

        std::string number() const { return _number; }

        TouristVehicleType type() const { return _type; }
        void setType(const TouristVehicleType &type) { _type = type; }

        int seatCount() const { return _seat_count; }
        void setSeatCount(int seat_count) { _seat_count = seat_count; }

        float perHourBookingCharge() const { return _per_hour_booking_charge; }
        void setPerHourBookingCharge(float per_hour_booking_charge) { _per_hour_booking_charge = per_hour_booking_charge; }

        PermitPointer permit() const { return _permit; }
        void setPermit(const PermitPointer &permit) { _permit = permit; }

        friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

inline int TouristVehicle::_counter = 1100;

#endif // TOURISTVEHICLE_H
