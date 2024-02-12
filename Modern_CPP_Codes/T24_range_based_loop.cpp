#include <iostream>
#include <vector>

class Employee {
    public:
        int id;
        std::string name;
        Employee(int id, std::string name): id(id), name(name){}
};

void printVector(const std::vector<Employee>& v) {
    for(const Employee& e: v)   // use const reference to avoid unnecessary call to copy constructor
        std::cout<<e.id<<"  "<<e.name<<std::endl;
    std::cout<<std::endl;
}

int main() {
    std::vector<Employee> v;
    v.push_back(Employee(10, "Krishna"));
    v.push_back(Employee(11, "Bhushan"));
    v.push_back(Employee(12, "Samiksha"));
    printVector(v);
    return 0;
}