#include "TrainTicket.hpp"

TrainTicket::TrainTicket(float price, TicketType type, TicketClass tclass)
    : _ticketPrice(price), _ticketType(type), _ticketClass(tclass) {}
std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs) {
    os << "_ticketPrice: " << rhs._ticketPrice
       << " _ticketType: " << static_cast<int> (rhs._ticketType)
       << " _ticketClass: " << static_cast<int> (rhs._ticketClass);
    os << "\n";
    return os;
}
