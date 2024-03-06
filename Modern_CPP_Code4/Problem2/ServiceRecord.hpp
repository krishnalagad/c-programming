#ifndef SERVICERECORD_HPP
#define SERVICERECORD_HPP

#include <iostream>
#include "ServiceType.hpp"

class ServiceRecord {
    private:
        std::string _serviceId;
        ServiceType _type;
        int _durationHours;
        float _charges;
        std::string _serviceAttendantName;
        std::string _serviceLocation;
        
    public:
        ServiceRecord() = default;
        ServiceRecord(const ServiceRecord&) = default;
        ServiceRecord(ServiceRecord&&) = default;
        ServiceRecord& operator=(const ServiceRecord&) = default;
        ServiceRecord& operator=(ServiceRecord&&) = default;
        ~ServiceRecord() = default;

        // custom parameterized constructor
        ServiceRecord(std::string id, ServiceType type, int hours, float charges, std::string name, std::string location);

        std::string serviceId() const { return _serviceId; }

        ServiceType type() const { return _type; }
        void setType(const ServiceType &type) { _type = type; }

        int durationHours() const { return _durationHours; }
        void setDurationHours(int durationHours) { _durationHours = durationHours; }

        float charges() const { return _charges; }
        void setCharges(float charges) { _charges = charges; }

        std::string serviceAttendantName() const { return _serviceAttendantName; }
        void setServiceAttendantName(const std::string &serviceAttendantName) { _serviceAttendantName = serviceAttendantName; }

        std::string serviceLocation() const { return _serviceLocation; }
        void setServiceLocation(const std::string &serviceLocation) { _serviceLocation = serviceLocation; }

        friend std::ostream &operator<<(std::ostream &os, const ServiceRecord &rhs);
};

#endif // SERVICERECORD_HPP
