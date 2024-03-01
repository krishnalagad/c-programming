#include <iostream>
#include <queue>
#include <string>

//enum class for automobile type
enum class AutomobileType { PRIVATE, COMMERCIAL };

class Automobile {
    private:
        std::string _id;
        float _price;
        AutomobileType _type;

    public:
        Automobile() = delete;
        Automobile(const Automobile&) = default;
        Automobile(Automobile&&) = default;
        Automobile& operator=(const Automobile&) = default;
        Automobile& operator=(Automobile&&) = default;
        ~Automobile() = default;
        Automobile(std::string id, float price, AutomobileType type) : _id(id), _price(price), _type(type) {}

        std::string getId() const { return _id; }
        float getPrice() const { return _price; }
        AutomobileType getType() const { return _type; }

        friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs){
            os << "_id: " << rhs._id
            << " _price: " << rhs._price
            << " _AutomobileType: " << static_cast<int> (rhs._type)
            << "\n";
            return os;
        }
};

// custom comparison function for priority queue
struct CompareAutomobiles {
    bool operator()(const Automobile& a1, const Automobile& a2) {
        // Compare based on price, higher price has higher priority
        return a1.getPrice() < a2.getPrice();
    }
};
/*
    g++ priority_queue.cpp -g -o app && time ./app && rm app
*/
int main() {
    std::priority_queue<Automobile, std::vector<Automobile>, CompareAutomobiles> autoQueue;

    // Add Automobile objects to the priority queue
    autoQueue.push(Automobile("A123", 25000.0, AutomobileType::PRIVATE));
    autoQueue.push(Automobile("B456", 30000.0, AutomobileType::COMMERCIAL));
    autoQueue.push(Automobile("C789", 20000.0, AutomobileType::PRIVATE));
    autoQueue.push(Automobile("D101", 35000.0, AutomobileType::COMMERCIAL));

    std::cout << "Vehicle at top priority of priority_queue is: " << autoQueue.top() << std::endl;

    // Retrieve and print the top element
    while (!autoQueue.empty()) {
        Automobile topAuto = autoQueue.top();
        std::cout << topAuto;
        autoQueue.pop();
    }

    return 0;
}