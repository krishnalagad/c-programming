#ifndef TRAINTICKET_HPP
#define TRAINTICKET_HPP

#include <iostream>
#include "TicketClass.hpp"
#include "TicketType.hpp"

class TrainTicket {
    private:
        float _ticketPrice;
        TicketType _ticketType;
        TicketClass _ticketClass;

    public:
        TrainTicket() = delete;
        TrainTicket(const TrainTicket&) = default;
        TrainTicket(TrainTicket&&) = default;
        TrainTicket& operator=(TrainTicket&&) = default;
        TrainTicket& operator=(const TrainTicket&) = default;
        ~TrainTicket() = default;

        TrainTicket(float price, TicketType type, TicketClass tclass);

        float ticketPrice() const { return _ticketPrice; }
        void setTicketPrice(float ticketPrice) { _ticketPrice = ticketPrice; }

        TicketType ticketType() const { return _ticketType; }
        void setTicketType(const TicketType &ticketType) { _ticketType = ticketType; }

        TicketClass ticketClass() const { return _ticketClass; }
        void setTicketClass(const TicketClass &ticketClass) { _ticketClass = ticketClass; }

        friend std::ostream &operator<<(std::ostream &os, const TrainTicket &rhs);
};

#endif // TRAINTICKET_HPP
