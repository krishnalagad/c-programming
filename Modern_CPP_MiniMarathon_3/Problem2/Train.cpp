#include "Train.hpp"

Train::Train(const std::string& number, const std::string& start, const std::string& destination, unsigned short hours, 
    unsigned short minutes, const TrainTicketContainer &tickets)
        : _trainNumber(number), _trainStartingStation(start), _trainDestinationStation(destination), 
        _trainDepartureHours(hours),_trainDepartureMinutes(minutes), _trainBookedTickets(tickets) {}
std::ostream &operator<<(std::ostream &os, const Train &rhs) {
    os << "_trainNumber: " << rhs._trainNumber
       << " _trainStartingStation: " << rhs._trainStartingStation
       << " _trainDestinationStation: " << rhs._trainDestinationStation
       << "\n_trainDepartureHours: " << rhs._trainDepartureHours
       << " _trainDepartureMinutes: " << rhs._trainDepartureMinutes;
    os << "\n_Ticket Data: \n";
    for (int i = 0; i < rhs._trainBookedTickets.size(); i++) {
        os << "_trainBookedTickets: " << *rhs._trainBookedTickets.at(i);
    }
    os << "\n";
    return os;
}
