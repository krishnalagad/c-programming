#include "Functionalities.hpp"

void createObjects(AutoPointerContainer &data) {
    data[0] = std::make_shared<Automobile>(
        "AUTO001", "Brand1", Category::DEFENCE, 340000.0f, "Model1"
    );
    data[1] = std::make_shared<Automobile>(
        "AUTO002", "Brand2", Category::PRIVATE, 450000.0f, "Model2"
    );
    data[2] = std::make_shared<Automobile>(
        "AUTO003", "Brand3", Category::TRANSPORT, 240000.0f, "Model3"
    );
}

void displayGreenPassCostById(const AutoPointerContainer &data, std::string id) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");

    auto pos = std::find_if(std::begin(data), std::end(data), [&](const AutoPointer& ptr) {
        return ptr->id() == id;
    });

    if (pos != std::end(data)) {
        float val = pos->get()->greenPassCost();
        std::cout << "Green pass cost is: " << val << std::endl;
    } else {
        throw RecordNotFoundException("Record not found with given ID!!\n");
    }
}

void displayAveragePrice(const AutoPointerContainer &data) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");

    auto totalAmount = std::accumulate(data.begin(), data.end(), 0.0f, [](float total, const AutoPointer& ptr){
        return total + ptr->price();
    });

    std::cout << "Average price of all the instances in an array: " << (totalAmount / data.size()) << std::endl;
}

void displayPrivilegeType(const AutoPointerContainer &data) {
    if (data.empty())
        throw CustomMessageException("Data container is empty!!");
    
    for(const AutoPointer& ptr: data) {
        std::cout << "Privilege Type: " << static_cast<int> (ptr->findPrivilegeType()) << std::endl;
    }
}
