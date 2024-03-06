#include "Functionalities.hpp"

/*
    Client code:
        g++ Main.cpp Functionalities.cpp Train.cpp TrainTicket.cpp -o app && time ./app && rm app
*/
int main() {
    TrainPointerContainer data;
    createObjects(data);

    try {
        std::optional<int> res =  getCountOfTrainsWith3TicketsBooked(data);
        if (res.has_value())
            std::cout << "Count of tickets: " << res.value() << std::endl;
        
        std::optional<TrainPointerContainer> trainData = getTrainsWithin3Hours(data, 10);
        if (trainData.has_value()) {
            std::cout << "\nTrain data whose departure time within 3 hours: \n";
            for (int i = 0; i < trainData.value().size(); i++) {
                std::cout << *trainData.value().at(i) << std::endl;
            }
        }

        std::optional<float> totalPrice = getTotalPriceOfAllTickets(data, "Train001");
        if (totalPrice.has_value())
            std::cout << "Total Price of tickets is: " << totalPrice.value() << "\n";
            
    } catch(CustomMessageException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(RecordNotFoundException& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}