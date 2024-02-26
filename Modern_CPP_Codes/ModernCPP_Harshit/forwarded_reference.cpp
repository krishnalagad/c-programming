#include <iostream>
#include <vector>

class DataModel {
    private:
        int n1;
        std::string& name;
        const std::string& grade;
        std::vector<int> data;

    public:
        DataModel() = delete;
        DataModel(int n1, std::string& name, const std::string& grade, std::vector<int>&& data)
            : n1(n1), name(name), grade(grade), data(std::move(data)) {}
        ~DataModel() = default;

        std::vector<int> getData() const { return data; }

        friend std::ostream &operator<<(std::ostream &os, const DataModel &rhs);
};

inline std::ostream &operator<<(std::ostream &os, const DataModel &rhs) {
    os << "n1: " << rhs.n1
       << ", name: " << rhs.name
       << ", grade: " << rhs.grade
       << ", data: ";
       for (int data: rhs.getData())
            os << data << " ";
    return os;
}

/*
    T : DatModel
    Args... : is for all other params
*/
template<typename T, typename... Args>
T relay(Args&&... args) {
    return T(std::forward<Args>(args)...);
}

/*
    g++ forwarded_reference.cpp -g -o app && time ./app && rm app

    - Main() is original source of data.
    - relay() is the middleman (relaying or forwarding function)
    - Constructor is the actual destination function where parameters should
      arrive as they are sent from main() without any changes.
*/      
int main() {
    int n1 = 10;
    std::string name = "Krishna";
    std::string grade = "A+";

    DataModel d1();

    DataModel data = relay<DataModel>(n1, name, grade, std::vector<int> {10, 20, 30});
    std::cout << data <<std::endl;

    return 0;
}

