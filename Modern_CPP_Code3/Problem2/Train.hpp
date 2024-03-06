#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "TrainTicket.hpp"

using TrainTicketPointer = std::shared_ptr<TrainTicket>;
using TrainTicketContainer = std::vector<TrainTicketPointer>;

class Train {
    private:
        std::string _trainNumber;
        std::string _trainStartingStation;
        std::string _trainDestinationStation;
        unsigned short _trainDepartureHours;
        unsigned short _trainDepartureMinutes;
        TrainTicketContainer _trainBookedTickets;
        
    public:
        Train() = delete;
        Train(const Train&) = default;
        Train(Train&&) = default;
        Train& operator=(Train&&) = default;
        Train& operator=(const Train&) = default;
        ~Train() = default;

        Train(const std::string& number, const std::string& start, const std::string& destination, unsigned short hours, 
                unsigned short minutes, const TrainTicketContainer& tickets);

        std::string trainNumber() const { return _trainNumber; }
        void setTrainNumber(const std::string &trainNumber) { _trainNumber = trainNumber; }

        std::string trainStartingStation() const { return _trainStartingStation; }
        void setTrainStartingStation(const std::string &trainStartingStation) { _trainStartingStation = trainStartingStation; }

        std::string trainDestinationStation() const { return _trainDestinationStation; }
        void setTrainDestinationStation(const std::string &trainDestinationStation) { _trainDestinationStation = trainDestinationStation; }

        unsigned short trainDepartureHours() const { return _trainDepartureHours; }
        void setTrainDepartureHours(unsigned short trainDepartureHours) { _trainDepartureHours = trainDepartureHours; }

        unsigned short trainDepartureMinutes() const { return _trainDepartureMinutes; }
        void setTrainDepartureMinutes(unsigned short trainDepartureMinutes) { _trainDepartureMinutes = trainDepartureMinutes; }

        TrainTicketContainer trainBookedTickets() const { return _trainBookedTickets; }
        void setTrainBookedTickets(const TrainTicketContainer &trainBookedTickets) { _trainBookedTickets = trainBookedTickets; }

        friend std::ostream &operator<<(std::ostream &os, const Train &rhs);
};

#endif // TRAIN_HPP
