#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include "Train.hpp"
#include "CustomMessageException.hpp"
#include "RecordNotFoundException.hpp"
#include <optional>

using TrainPointer = std::shared_ptr<Train>;
using TrainPointerContainer = std::vector<TrainPointer>;

/*
    Function takes lvalue reference of TrainPointerContainer where Container is std::vector of traingPointer
    and TrainPointer is shared pointer of class Train and returns void.
*/
void createObjects(TrainPointerContainer& data);

/*
    Function takes constant lvalue reference of TrainPointerContainer where Container is std::vector of traingPointer
    and TrainPointer is shared pointer of class Train and returns optional of intger.
*/
std::optional<int> getCountOfTrainsWith3TicketsBooked(const TrainPointerContainer& data);

/*
    Function takes lvalue reference of TrainPointerContainer, integer where Container is std::vector of traingPointer
    and TrainPointer is shared pointer of class Train and returns optional of TrainPointerContainer.
*/
std::optional<TrainPointerContainer> getTrainsWithin3Hours(const TrainPointerContainer& data, int time);

/*
    Function takes constant lvalue reference of TrainPointerContainer, string  where Container is std::vector of traingPointer
    and TrainPointer is shared pointer of class Train and returns optional of float.
*/
std::optional<float> getTotalPriceOfAllTickets(const TrainPointerContainer& data, std::string num);

#endif // FUNCTIONALITIES_HPP
