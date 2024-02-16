#include "Functionalities.hpp"
#include <algorithm>

void createObjects(TrainPointerContainer &data) {
    data.push_back(
        std::make_shared<Train>(
            std::move("Train001"), std::move("Pune"), std::move("Mumbai"), 11, 56,
            TrainTicketContainer{
                {std::make_shared<TrainTicket>(300.0f, TicketType::RESERVED, TicketClass::FIRST)},
                {std::make_shared<TrainTicket>(1200.0f, TicketType::GENERAL, TicketClass::AC)},
                {std::make_shared<TrainTicket>(120.0f, TicketType::WAITING, TicketClass::SECOND)},
                {std::make_shared<TrainTicket>(110.0f, TicketType::GENERAL, TicketClass::SECOND)}}));
    
    data.push_back(
        std::make_shared<Train>(
            std::move("Train002"), std::move("Pune"), std::move("Mumbai"), 23, 9,
            TrainTicketContainer{
                {std::make_shared<TrainTicket>(3000.0f, TicketType::RESERVED, TicketClass::FIRST)},
                {std::make_shared<TrainTicket>(11200.0f, TicketType::GENERAL, TicketClass::AC)},
                {std::make_shared<TrainTicket>(1220.0f, TicketType::WAITING, TicketClass::SECOND)},
                {std::make_shared<TrainTicket>(1130.0f, TicketType::GENERAL, TicketClass::SECOND)}}));
    
    data.push_back(
        std::make_shared<Train>(
            std::move("Train003"), std::move("Pune"), std::move("Mumbai"), 12, 23,
            TrainTicketContainer{
                {std::make_shared<TrainTicket>(30000.0f, TicketType::RESERVED, TicketClass::FIRST)},
                {std::make_shared<TrainTicket>(121100.0f, TicketType::GENERAL, TicketClass::AC)},
                {std::make_shared<TrainTicket>(1220.0f, TicketType::WAITING, TicketClass::SECOND)}}));

    data.push_back(
        std::make_shared<Train>(
            std::move("Train004"), std::move("Pune"), std::move("Mumbai"), 13, 34,
            TrainTicketContainer{
                {std::make_shared<TrainTicket>(30000.0f, TicketType::RESERVED, TicketClass::FIRST)},
                {std::make_shared<TrainTicket>(121100.0f, TicketType::GENERAL, TicketClass::AC)},
                {std::make_shared<TrainTicket>(1220.0f, TicketType::WAITING, TicketClass::SECOND)}}));
}

std::optional<int> getCountOfTrainsWith3TicketsBooked(const TrainPointerContainer &data) {
    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");

    int n = std::count_if(std::begin(data), std::end(data), [](const TrainPointer& ptr){
            return ptr->trainBookedTickets().size() > 2;
    });

    if (n == 0)
        return std::nullopt;

    return n;
}

std::optional<TrainPointerContainer> getTrainsWithin3Hours(const TrainPointerContainer &data, int time) {
    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");
    
    TrainPointerContainer result;

    for (const TrainPointer& ptr: data) {
        if ((ptr->trainDepartureHours() - time == 1) || (ptr->trainDepartureHours() - time == 2) || (
            ptr->trainDepartureHours() - time == 3)) {
                result.push_back(ptr);
        }
    }
    
    if (result.empty())
        return std::nullopt;
    
    return result;
}

std::optional<float> getTotalPriceOfAllTickets(const TrainPointerContainer &data, std::string num) {
    if (data.empty()) 
        throw CustomMessageException("Data container is empty!!");
    
    auto pos = std::find_if(std::begin(data), std::end(data), [&](const TrainPointer& ptr) {
        return ptr->trainNumber() == num;
    });

    float total = 0.0f;
    if (pos != std::end(data)) {
        TrainPointer train = *pos;
        if (train->trainBookedTickets().empty()) 
            throw RecordNotFoundException("Train ticket container is empty!!");
        for(const TrainTicketPointer ticketPtr: train->trainBookedTickets()) {
            total += ticketPtr->ticketPrice();
        }
    }

    if (total == 0.0f)
        return std::nullopt;

    return total;
}
